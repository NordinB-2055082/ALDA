#include "CSVReader.h"
#include "Product.h"
using namespace std;

CSVReader::CSVReader(const string& filename) {
    inputFile.open(filename);

    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
}

CSVReader::~CSVReader() {
    inputFile.close();
}

void CSVReader::readCSV() {
    string line;
    while (getline(inputFile, line)) {

        // Split the line into fields
        vector<string> fields = split(line, ',');

        // Extract values for non-title fields
        string asin = fields[0];
        string title;
        // For some reason when there are double quotes in the line the asin starts with ", i can't find where it comes from, 
        // so i avoided this problem with the following simple code
        if (asin[0] == '"') {
            asin.erase(0, 1);
        }
        // Check if the title field is enclosed in double quotes
        if (fields[1][0] == '"') {
            // Concatenate all fields from the title field until the last field enclosed in double quotes
            for (size_t i = 1; i < fields.size(); ++i) {
                title += fields[i];
                if (fields[i].back() == '"') {
                    // If the last field ends with double quotes, remove them and break the loop
                    // If we don't do this we have "" in our data
                    title = removeQuotes(title);
                    break;
                }
                else {
                    title += ','; // Add a comma between fields
                }
            }
        }
        else {
            // The title field does not contain commas
            title = fields[1];
        }

        // Process the rest of the fields, 
        // we count from the back to the front to ignore when title made more fields because of the ',' in the value of title itself
        string imgUrl = fields[fields.size() - 9];
        string productURL = fields[fields.size() - 8];
        double stars = stod(fields[fields.size() - 7]);
        int reviews = stoi(fields[fields.size() - 6]);
        double price = stod(fields[fields.size() - 5]);
        double listPrice = stod(fields[fields.size() - 4]);
        int category_id = stoi(fields[fields.size() - 3]);
        bool isBestSeller = (fields[fields.size() - 2] == "True");
        int boughtInLastMonth = stoi(fields[fields.size() - 1]);

        Product product = { asin, title, imgUrl, productURL, stars, reviews, price, listPrice, category_id, isBestSeller, boughtInLastMonth };
 

    }
}

vector<string> CSVReader::split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string CSVReader::removeQuotes(const string& s) {
    string result = s;
    result.erase(remove(result.begin(), result.end(), '"'), result.end());
    return result;
}
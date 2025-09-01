#include <bits/stdc++.h>
#include "json.hpp"   // include the JSON library

using namespace std;
using json = nlohmann::json;

// Function to convert number string from given base to decimal (as long long)
long long convertToDecimal(const string& value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = 10 + (tolower(c) - 'a');
        else throw runtime_error("Invalid character in number");
        if (digit >= base) throw runtime_error("Digit out of range for base");
        result = result * base + digit;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read whole input into a string
    string input((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());

    // Parse JSON
    json j = json::parse(input);

    // Extract n and k
    int n = j["keys"]["n"];
    int k = j["keys"]["k"];

    cout << "n = " << n << ", k = " << k << "\n";

    // Store roots
    vector<long long> roots;

    for (int i = 1; i <= n; i++) {
        string idx = to_string(i);
        int base = stoi(j[idx]["base"].get<string>());
        string value = j[idx]["value"];
        long long decimalValue = convertToDecimal(value, base);
        cout << "Root " << i << " (base " << base << "): " << value
             << " -> " << decimalValue << "\n";
        roots.push_back(decimalValue);
    }

    // TODO: use roots and k for your main algorithm
    cout << "Total roots collected: " << roots.size() << "\n";

    return 0;
}

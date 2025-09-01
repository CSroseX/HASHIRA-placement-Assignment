# Shamir's Secret Sharing - Assignment Solution

## Overview
This program implements Shamir's Secret Sharing scheme to reconstruct a secret from a threshold number of keys using Lagrange Interpolation.

## How to Run

### Prerequisites
- C++17 compatible compiler (e.g., g++)
- The following files in the same directory:
  - `assignment.cpp`
  - `json.hpp` (nlohmann single-header library)
  - `input.txt` (JSON formatted input file)

### Compilation
```bash
g++ assignment.cpp -o assignment.exe
```

### Execution
```bash
assignment.exe < input.txt
```

## Solution Methodology

The solution implements Shamir's Secret Sharing scheme by first parsing a JSON input file that contains the total number of keys (n), the threshold number of keys needed for reconstruction (k), and a list of keys with their values in different bases. Each key is then converted from its specified base into a decimal value. Using at least k keys, the algorithm applies Lagrange Interpolation to accurately reconstruct the original secret. Finally, the secret is recovered and output, ensuring that it can only be obtained when the required threshold number of valid keys is provided.

## Requirements

- C++17 compatible compiler (e.g., g++)
- nlohmann/json single-header library (`json.hpp`) in the same directory
- Valid JSON input file (`input.txt`) following the expected structure

## Example Usage

### Input (`input.txt`)
```json
{
  "keys": [
    {"base": 10, "value": "123"},
    {"base": 16, "value": "7B"},
    {"base": 8, "value": "173"}
  ],
  "k": 2,
  "n": 3
}
```

### Command
```bash
assignment.exe < input.txt
```

### Output
```
Secret: 123
```

## JSON Schema

The input file should follow this structure:

```json
{
  "n": <number>,           // Total number of keys
  "k": <number>,           // Threshold keys required
  "keys": [                // Array of key objects
    {
      "base": <number>,    // Number base (2-36)
      "value": "<string>"  // Value in specified base
    }
  ]
}
```

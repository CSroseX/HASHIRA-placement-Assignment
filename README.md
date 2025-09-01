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

The solution implements Shamir's Secret Sharing scheme through the following steps:

1. **JSON Input Parsing**: The program reads a JSON input file containing:
   - `n`: Total number of keys
   - `k`: Threshold number of keys required for reconstruction
   - `keys`: List of keys with their base and value representations

2. **Base Conversion**: Each key value is decoded from its specified base representation into decimal form

3. **Lagrange Interpolation**: Using at least `k` keys, the algorithm applies Lagrange Interpolation to reconstruct the original secret

4. **Secret Recovery**: The reconstructed secret is output, ensuring it can only be recovered with the threshold number of valid keys

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

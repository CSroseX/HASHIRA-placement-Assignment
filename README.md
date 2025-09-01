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
n = 10, k = 7
Root 1 (base 6): 13444211440455345511 -> 995085094601491
Root 2 (base 15): aed7015a346d635 -> 320923294898495900
Root 3 (base 15): 6aeeb69631c227c -> 196563650089608567
Root 4 (base 16): e1b5e05623d881f -> 1016509518118225951
Root 5 (base 8): 316034514573652620673 -> 3711974121218449851
Root 6 (base 3): 2122212201122002221120200210011020220200 -> -7658124175476059155
Root 7 (base 3): 20120221122211000100210021102001201112121 -> 8262650902798790847
Root 8 (base 6): 20220554335330240002224253 -> 3384843392724653865
Root 9 (base 12): 45153788322a1255483 -> 7172521759749202275
Root 10 (base 7): 1101613130313526312514143 -> -1357032052919294591
Total roots collected: 10
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

# Compiling
```
gcc clock_skew.c -o clock_skew
```

# Usage
```
# ./clock_skew
querying status
adjtime returned = 0.000000
# ./clock_skew plus
skewing positive
adjtime returned = 2.000000
# ./clock_skew minus
querying status
adjtime returned = 1.998000
```


#!/bin/bash

# Output file for test results
RESULTS_FILE="results.log"
> $RESULTS_FILE  # Clear previous results

# Iterate through BUFFER_SIZE values from -1 to 100
for BUFFER_SIZE in $(seq -1 1 100); do
    echo "Testing BUFFER_SIZE=$BUFFER_SIZE" >> $RESULTS_FILE

    # Compile with the current BUFFER_SIZE value
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFFER_SIZE main.c get_next_line.c get_next_line_utils.c -o test 2>> $RESULTS_FILE

    # Check if compilation was successful
    if [ $? -eq 0 ]; then
        # Run the compiled program and save the output
        ./test > output.txt

        # Compare output with reference file
        if [ "$BUFFER_SIZE" -le 0 ]; then
            # Compare output with an empty file
            if [ ! -s output.txt ]; then
                echo "BUFFER_SIZE=$BUFFER_SIZE: ✅ Test Passed (Empty Output)" >> $RESULTS_FILE
            else
                echo "BUFFER_SIZE=$BUFFER_SIZE: ❌ Test Failed (Should Be Empty)" >> $RESULTS_FILE
            fi
        else
            # Compare output with reference file for non-negative values
            if diff -q output.txt test.txt > /dev/null; then
                echo "BUFFER_SIZE=$BUFFER_SIZE: ✅ Test Passed" >> $RESULTS_FILE
            else
                echo "BUFFER_SIZE=$BUFFER_SIZE: ❌ Test Failed" >> $RESULTS_FILE
            fi
        fi
    else
        echo "BUFFER_SIZE=$BUFFER_SIZE: ⚠️ Compilation Failed" >> $RESULTS_FILE
    fi

done
echo "Testing complete. Check '$RESULTS_FILE' for results."
#!/bin/bash

passed=0
failed=0
for ((i=1; i<=10; i++)); do
	./task1.sh 7 5 5 "$i"
	folder_name="cs527_lab1_test_${i}"
	./task3 -d "${folder_name}"

	file1="${folder_name}/readme.txt"
	file2="log2.txt"

	if cmp -s "$file1" "$file2"; then
	    echo "Test ${i} PASSED"
	    ((passed++))
	else
	    echo "Test ${i} FAILED"
	    ((failed++))
	fi
done

echo "Passed Test Cases: ${passed}"
echo "Failed Test Cases: ${failed}"

#!/bin/bash

Tot_Files=0
Tot_Folders=0
Max_Level=0

create_files() {
    local N=$1
    local D=$2
    local K=$3
    local C_D=$4
    local Next_D=$((C_D + 1))
    
    if [ $Max_Level -lt $C_D ]
    then
    		Max_Level=$((C_D))
    fi

    local L=$(shuf -i 1-"$N" -n 1)

    local folders=()

    for ((i=0; i<L; i++)); do
        local random_number=$(( RANDOM % 2 ))
        if [ "$random_number" -eq 0 ]; then
            touch "depth_${C_D}_file_$i.txt"
            echo $text >> "depth_${C_D}_file_$i.txt"
            ((Tot_Files++))
        else
            mkdir "depth_${C_D}_directory_$i"
            ((Tot_Folders++))
            folders+=("$PWD/depth_${C_D}_directory_$i")
        fi
    done

    local no_folders="${#folders[@]}"

    if [ "$C_D" -lt "$D" ]; then
        for ((j=0; j<no_folders; j++)); do
            local path="${folders[$j]}"
            if [ -d "$path" ]; then
                pushd "$path" > /dev/null
                create_files "$N" "$D" "$K" "$Next_D"
                popd > /dev/null
            else
                echo "Directory $path not found."
            fi
        done
    fi
}

max_char=$(( $3 * 1024 ))
echo "Write some text which will be stored in files: "
echo "NOTE: Maximum characters - $max_char"
read text


while [ ${#text} -gt $max_char ]; do
    echo "Maximum limit exceeded!! Please write again: "
    read text
done



# Clean up if previous directory exists
if [ -d "cs527_lab1_test_$4" ]; then
    rm -r "cs527_lab1_test_$4"
fi

mkdir "cs527_lab1_test_$4"
pushd "cs527_lab1_test_$4" > /dev/null

# Call the function with appropriate arguments and initial path
create_files "$1" "$2" "$3" 0

# Return to the original directory
popd > /dev/null

cd "cs527_lab1_test_$4"

echo "Total normal files $Tot_Files" >> "readme.txt"
echo "Total Folders $Tot_Folders" >> "readme.txt"
echo "Maximum levels $Max_Level" >> "readme.txt"

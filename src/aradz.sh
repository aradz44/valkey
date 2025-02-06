#!/bin/bash

# Set the value to be used for all keys
VALUE="abcd111111111111111111111111111111111111111111rxyz"

# Loop to set 10,000 keys
for i in {1..10000}
do
    # Generate the key with the format key:0000000X, padded with zeroes to length 18
    KEY=$(printf "key:%031d" $i)
    
    # Set the key-value pair using valkey-cli
    ./valkey-cli set "$KEY" "$VALUE"
done

echo "Finished setting 10,000 keys."

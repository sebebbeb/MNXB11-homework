#!/bin/bash

########################################################################
# project_data_processor.sh - Script for processing climate data for project
#
# Author: Sebastian Magnusson
#
# Description: This script automates the process of cleaning and filtering
#              climate data from multiple stations. It handles basic errors 
#              such as missing files or invalid inputs.
#
# Disclaimer: ChatGPT was used in order to help with syntax, a bit on the "basic errors" mentioned above 
#              and to see if the implementation of something was done in a good way.  
#
# Usage: ./project_data_processor.sh file1.csv file2.csv ...
#
########################################################################

# Function to show usage
usage() {
    echo "Usage: $0 <datafile1> <datafile2> ... "
    exit 1
}

# Function to log messages
log() {
    local LOG_MSG=$1
    local LOG_TIMESTAMP=$(date -Iseconds)
    echo "[${LOG_TIMESTAMP}]: $LOG_MSG"
}

# Function to clean data (Example: remove invalid rows)
clean_data() {
    local INPUT_FILE=$1
    local CLEANED_FILE="cleaned_${INPUT_FILE}"
    
    log "Cleaning data for file: $INPUT_FILE"
    
    # Example cleaning: Remove lines with missing values (assuming a CSV format with 5 columns)
    awk -F"," 'NF==5' "$INPUT_FILE" > "$CLEANED_FILE"
    
    if [[ $? -ne 0 ]]; then
        log "Error cleaning data for file $INPUT_FILE"
        exit 1
    fi
    
    log "Data cleaned successfully. Output: $CLEANED_FILE"
    echo $CLEANED_FILE
}

# Function to filter data (Example: filter by a specific date)
filter_data() {
    local CLEANED_FILE=$1
    local FILTER_DATE=$2
    local FILTERED_FILE="filtered_${CLEANED_FILE}"
    
    log "Filtering data for date: $FILTER_DATE in file: $CLEANED_FILE"
    
    # Example filter: Select only rows containing the specified date
    grep "$FILTER_DATE" "$CLEANED_FILE" > "$FILTERED_FILE"
    
    if [[ $? -ne 0 ]]; then
        log "Error filtering data for file $CLEANED_FILE"
        exit 1
    fi
    
    log "Data filtered successfully for date $FILTER_DATE. Output: $FILTERED_FILE"
    echo $FILTERED_FILE
}

# Check if at least one file is provided
if [[ $# -eq 0 ]]; then
    log "No data files provided."
    usage
fi

# Process each file passed as an argument
for DATAFILE in "$@"; do
    # Check if file exists
    if [[ ! -f "$DATAFILE" ]]; then
        log "File not found: $DATAFILE"
        exit 1
    fi

    log "Processing file: $DATAFILE"
    
    # Step 1: Clean the data
    CLEANED_FILE=$(clean_data "$DATAFILE")
    
    # Step 2: Filter data for a specific date (e.g., 2020-07-15 as an example)
    FILTER_DATE="2020-07-15"  # Changable
    FILTERED_FILE=$(filter_data "$CLEANED_FILE" "$FILTER_DATE")
    
    log "File $FILTERED_FILE ready for further analysis."
done

log "All files processed successfully."

exit 0

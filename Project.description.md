Project Description: Hashtag Suggestion Tool

This project is a C++ program designed to assist users in generating hashtags based on predefined categories. It utilizes various standard libraries for input/output operations, data manipulation, and string handling.

Key Components:

Category Display Function:

Displays categories in columns with aligned separators for easy readability. Each category is associated with a unique number.
Hashtag Display Function:

Upon user selection of a category by entering the respective number, displays hashtags associated with that category. Hashtags are formatted to include the category name followed by specific keywords.
Related Hashtag Suggestion Function:

Provides suggestions for hashtags related to the user's input. If the user enters a category number and a category name, the program suggests additional hashtags related to that category.
Implementation Details:

Libraries Used:

<iostream> for standard input/output operations.
<vector> and <string> for managing and manipulating collections of strings.
<unordered_map> for efficient storage and retrieval of hashtag data.
<algorithm> and <cctype> for transforming and manipulating strings (e.g., converting to uppercase).
<iomanip> for setting the width of output columns.
Main Function:

Contains a list of 75 predefined categories along with associated hashtags.
Prompts the user to select a category by entering a number from 1 to 75.
Outputs the selected category's hashtags in a structured format.
Usage Scenario:

The program begins by displaying a formatted list of 75 categories, allowing the user to choose one by entering its corresponding number. Upon selection, it outputs hashtags related to the chosen category. Additionally, if the user specifies both the category number and its name, the program suggests further hashtags related to that specific input.

Purpose:

This project serves as an educational tool to demonstrate how hashtag suggestion software can categorize and recommend relevant tags based on user input. It showcases effective use of C++ libraries for data handling and manipulation, providing a practical example of command-line interface application development.

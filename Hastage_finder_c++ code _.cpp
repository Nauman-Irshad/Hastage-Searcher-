#include <limits>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

void displayCategories(const vector<string>& categories) {
    int numColumns = 5;
    int columnWidth = 20;
    int numRows = (categories.size() + numColumns - 1) / numColumns;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numColumns; ++col) {
            int index = col * numRows + row;
            if (index < categories.size()) {
                int number = index + 1;
                cout << setw(3) << right << number << ". " << setw(columnWidth - 3) << left << categories[index];
            }
            else {
                cout << setw(columnWidth) << " ";
            }
        }
        cout << endl;
    }
}

void displayHashtags(const vector<string>& hashtags) {
    cout << endl;
    cout << "Here are some hashtags for your selected category:" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < hashtags.size(); ++i) {
        cout << "#" << hashtags[i] << " ";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}

void suggestRelatedHashtags(const unordered_map<string, vector<string>>& hashtagMap, const string& categoryName) {
    string uppercaseCategory = categoryName;
    transform(uppercaseCategory.begin(), uppercaseCategory.end(), uppercaseCategory.begin(), ::toupper);

    if (hashtagMap.find(uppercaseCategory) != hashtagMap.end()) {
        const vector<string>& relatedHashtags = hashtagMap.at(uppercaseCategory);
        displayHashtags(relatedHashtags);
    }
    else {
        cout << "No related hashtags found for category " << categoryName << "." << endl;
    }
}

int main() {
    unordered_map<string, vector<string>> hashtagMap = {
        {"PHYSICS", {"Science", "Mathematics", "Astronomy", "Engineering", "Quantum"}},
        {"MAGIC", {"Illusion", "Magician", "Trick", "SleightOfHand", "MagicTrick"}},
        {"TECHNOLOGY", {"Innovation", "Tech", "Gadgets", "Digital", "FutureTech"}},
        {"HEALTH", {"Fitness", "Wellness", "Nutrition", "Medicine", "HealthyLiving"}},
        {"TRAVEL", {"Wanderlust", "Adventure", "Explore", "Vacation", "TravelGram"}},
        {"FOOD", {"Foodie", "Cooking", "Recipes", "HealthyEating", "FoodPhotography"}},
        {"FASHION", {"Style", "Fashionista", "Clothing", "Accessories", "OOTD"}},
        {"EDUCATION", {"Learning", "School", "Knowledge", "Teachers", "EducationForAll"}},
        {"FITNESS", {"Workout", "Exercise", "GymLife", "FitnessMotivation", "FitFam"}},
        {"SPORTS", {"Athlete", "SportsNews", "TeamSports", "SportsPhotography", "Fitness"}},
        {"MUSIC", {"Musician", "Concert", "MusicProduction", "MusicLover", "Songwriter"}},
        {"MOVIES", {"Film", "MovieNight", "Cinema", "Actors", "MovieQuotes"}},
        {"PHOTOGRAPHY", {"PhotoOfTheDay", "Photographer", "Camera", "PortraitPhotography", "NaturePhotography"}},
        {"NATURE", {"NatureLovers", "WildlifePhotography", "OutdoorAdventure", "ExploreNature", "NatureGram"}},
        {"ART", {"Artistic", "Painting", "Sculpture", "ArtGallery", "ArtLovers"}},
        {"GAMING", {"Gamer", "GamingCommunity", "VideoGames", "PCGaming", "ConsoleGaming"}},
        {"BOOKS", {"Bookworm", "ReadingList", "BookRecommendations", "Literature", "Library"}}
    };

    vector<string> categories = {
        "Physics", "Magic", "Technology", "Health", "Travel",
        "Food", "Fashion", "Education", "Fitness", "Sports",
        "Music", "Movies", "Photography", "Nature", "Art",
        "Gaming", "Books", "Science", "Business", "Finance",
        "Lifestyle", "DIY", "Pets", "Parenting", "Beauty",
        "Cooking", "Crafts", "Gardening", "Automotive", "Real Estate",
        "Dating", "Career", "Home Decor", "Spirituality", "History",
        "Politics", "Culture", "Luxury", "Adventure", "Economics"
    };

    bool exitProgram = false;

    while (!exitProgram) {
        displayCategories(categories);
        int choice;
        cout << endl;
        cout << "Enter the number of your chosen category (1 to " << categories.size() << "): ";
        cin >> choice;

        if (choice >= 1 && choice <= categories.size()) {
            string selectedCategory = categories[choice - 1];
            suggestRelatedHashtags(hashtagMap, selectedCategory);
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and " << categories.size() << "." << endl;
        }

        int continueOption;
        cout << "Enter 1 to search again or 2 to exit: ";
        cin >> continueOption;

        if (continueOption == 2) {
            exitProgram = true;
        }
        else if (continueOption != 1) {
            cout << "Invalid option. Exiting program." << endl;
            exitProgram = true;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

#include "utility.h"

using namespace std;

//there are two test files. feattest & spelltest. They are both .csv but the program will add that on for you. It will also add the .txt when you label the new file.
//the eventual intent is to get a couple different excel files from a dungeons and dragons type game. The resource site is free to use but needs an update. d20pfsrd.org
//the two "databases" they have are just large excel sheets that are very difficult to search or manage. https://www.d20pfsrd.com/magic/tools/spells-db/ and https://www.d20pfsrd.com/feats/feats-db
//my goal eventually, is to have these added to a SQL database so that it can be more easily accessed and searched through.
//currently the resources I tried to work with for creating an excel file with the csv's from this site were too basic. The way excel works is it uses something called OOXML. But xlsx files are basically zip archives with multiple
//xml files within them. making it very difficult to create from scratch.
//I was pointed at https://github.com/jmcnamara/libxlsxwriter for a library to help create them, but I could not get that library to load properly. I'm still playing with it, but it's a little outside my expertise.
//currently the program will take a csv file for the relative 'data' type, feat or spell, and convert it to a txt file with the original formatting for xml. 
//I used an overall template class and set up specialized structs for the feats and spells. That way the program can work dynamically with the type I need it to. I can also add more specialized structs in the event
//that I want to add additional rule databases objects, like classes, races, or class archetypes. Doing it with the template let me be more flexible than hard coding specific structs and then having to rewrite
//the methods for each. I hope that specialization covers the requirement for 2classes/structs as it currently sets up 2 structs dependant on a single template class.
//thank you.

enum choice { FEATS = 1, SPELLS, QUIT };

int main()
{
    TemplateClass<feats> allFeats;
    vector<feats> featTable;
    TemplateClass<Spells> allSpells;
    vector<Spells> spellTable;

    int choice;
    do {
        choice = menu();
        string temp;
        string newName;
        switch (choice) {
        case FEATS:
            cout << "Please enter your Feat filename." << endl;
            featTable = allFeats.parseData();
            cout << "What do you want to call your new file?" << endl;
            newName = getExcelname();
            allFeats.createExcelFile(featTable, newName);
            cout << newName << " has been created." << endl;
            break;
        case SPELLS:
            cout << "Please enter your Spells filename." << endl;
            spellTable = allSpells.parseData();
            cout << "What do you want to call your new file?" << endl;
            newName = getExcelname();
            allSpells.createExcelFile(spellTable, newName);
            cout << newName << " has been created." << endl;
        }

    } while (choice != QUIT);
    return 0;
}
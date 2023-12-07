#include "data.h"

using namespace std;

template class TemplateClass<feats>;
template class TemplateClass<Spells>;

template <typename Type>
TemplateClass<Type>::TemplateClass() {};

template <typename Type>
TemplateClass<Type>::~TemplateClass() {
	clear();
}

template<typename Type>
vector<pair<string, string>> getAttributes(const Type& object)
{
    return vector<pair<string, string>>();
}

template <>
// Specialization for feats struct.
    vector<pair<string, string>> getAttributes(const feats& feats) {
        return {
            {"Name", feats.name},
            {"Type", feats.type},
            {"Description", feats.description},
            {"Prereq", feats.prereq},
            {"PrereqFeat", feats.prereqFeat},
            {"Benefit", feats.benefit},
            {"Normal", feats.normal},
            {"Special", feats.special},
            {"Source", feats.source},
            {"FullText", feats.fulltext},
            {"Teamwork", feats.teamwork ? "true" : "false"},
            {"Critical", feats.critical ? "true" : "false"},
            {"Grit", feats.grit ? "true" : "false"},
            {"Style", feats.style ? "true" : "false"},
            {"Performance", feats.performance ? "true" : "false"},
            {"Racial", feats.racial ? "true" : "false"},
            {"Companion", feats.companion ? "true" : "false"},
            {"Race", feats.race},
            {"Note", feats.note},
            {"Goal", feats.goal},
            {"Completion", feats.completion},
            {"Multiples", feats.multiples ? "true" : "false"},
            {"SuggestedTraits", feats.suggestedTraits}
        };
};

// Specialization for Spells struct
template <>
    static vector<pair<string, string>> getAttributes(const Spells& attributes) {
        return {
            {"Name", attributes.name},
            {"School", attributes.school},
            {"Subschool", attributes.subschool},
            {"Descriptor", attributes.descriptor},
            {"Spell Level", attributes.spell_level},
            {"Casting Time", attributes.casting_time},
            {"Components", attributes.components},
            {"Costly Components", attributes.costly_components},
            {"Range", attributes.range},
            {"Area", attributes.area},
            {"Effect", attributes.effect},
            {"Targets", attributes.targets},
            {"Duration", attributes.duration},
            {"Dismissible", attributes.dismissible ? "true" : "false"},
            {"Shapeable", attributes.shapeable ? "true" : "false"},
            {"Saving Throw", attributes.saving_throw},
            {"Spell Resistance", attributes.spell_resistance},
            {"Description", attributes.description},
            {"Formatted Description", attributes.description_formatted},
            {"Source", attributes.source},
            {"Full Text", attributes.full_text},
            {"Verbal", attributes.verbal ? "true" : "false"},
            {"Somatic", attributes.somatic ? "true" : "false"},
            {"Material", attributes.material ? "true" : "false"},
            {"Focus", attributes.focus ? "true" : "false"},
            {"Divine Focus", attributes.divine_focus ? "true" : "false"},
            {"Sorcerer", attributes.sor},
            {"Wizard", attributes.wiz},
            {"Cleric", attributes.cleric},
            {"Druid", attributes.druid},
            {"Ranger", attributes.ranger},
            {"Bard", attributes.bard},
            {"Paladin", attributes.paladin},
            {"Alchemist", attributes.alchemist},
            {"Summoner", attributes.summoner},
            {"Witch", attributes.witch},
            {"Inquisitor", attributes.inquisitor},
            {"Oracle", attributes.oracle},
            {"Antipaladin", attributes.antipaladin},
            {"Magus", attributes.magus},
            {"Adept", attributes.adept},
            {"Deity", attributes.deity},
            {"SLA Level", attributes.SLA_Level},
            {"Domain", attributes.domain},
            {"Short Description", attributes.short_description},
            {"Acid", attributes.acid ? "true" : "false"},
            {"Air", attributes.air ? "true" : "false"},
            {"Chaotic", attributes.chaotic ? "true" : "false"},
            {"Cold", attributes.cold ? "true" : "false"},
            {"Curse", attributes.curse ? "true" : "false"},
            {"Darkness", attributes.darkness ? "true" : "false"},
            {"Death", attributes.death ? "true" : "false"},
            {"Disease", attributes.disease ? "true" : "false"},
            {"Earth", attributes.earth ? "true" : "false"},
            {"Electricity", attributes.electricity ? "true" : "false"},
            {"Emotion", attributes.emotion ? "true" : "false"},
            {"Evil", attributes.evil ? "true" : "false"},
            {"Fear", attributes.fear ? "true" : "false"},
            {"Fire", attributes.fire ? "true" : "false"},
            {"Force", attributes.force ? "true" : "false"},
            {"Good", attributes.good ? "true" : "false"},
            {"Language Dependent", attributes.language_dependent ? "true" : "false"},
            {"Lawful", attributes.lawful ? "true" : "false"},
            {"Light", attributes.light ? "true" : "false"},
            {"Mind Affecting", attributes.mind_affecting ? "true" : "false"},
            {"Pain", attributes.pain ? "true" : "false"},
            {"Poison", attributes.poison ? "true" : "false"},
            {"Shadow", attributes.shadow ? "true" : "false"},
            {"Sonic", attributes.sonic ? "true" : "false"},
            {"Water", attributes.water ? "true" : "false"},
            {"Linktext", attributes.linktext},
            {"ID", attributes.id},
            {"Material Costs", attributes.material_costs},
            {"Bloodline", attributes.bloodline},
            {"Patron", attributes.patron},
            {"Mythic Text", attributes.mythic_text},
            {"Augmented", attributes.augmented},
            {"Mythic", attributes.mythic ? "true" : "false"},
            {"Bloodrager", attributes.bloodrager},
            {"Shaman", attributes.shaman},
            {"Psychic", attributes.psychic},
            {"Medium", attributes.medium},
            {"Mesmerist", attributes.mesmerist},
            {"Occultist", attributes.occultist},
            {"Spiritualist", attributes.spiritualist},
            {"Skald", attributes.skald},
            {"Investigator", attributes.investigator},
            {"Hunter", attributes.hunter},
            {"Haunt Statistics", attributes.haunt_statistics},
            {"Ruse", attributes.ruse},
            {"Draconic", attributes.draconic ? "true" : "false"},
            {"Meditative", attributes.meditative ? "true" : "false"},
            {"Summoner Unchained", attributes.summoner_unchained ? "true" : "false"}
        };
};

template <typename Type>
vector<Type> TemplateClass<Type>::parseData() {
	ifstream fileName(getFilename(), ios::in);
	vector<Type> table;
	string line;
	if (!fileName.is_open()) {
		cout << "File not found." << endl;
	}
		while (getline(fileName, line)) {
			Type newObject;
			stringstream ss(line);
			newObject.parseLine(ss);
			table.emplace_back(newObject);
		}
		fileName.close();
		return table;
	}

template <typename Type>
void TemplateClass<Type>::clear() {

}

void feats::parseLine(istream& ss) {
getline(ss, name, ',');
getline(ss, type, ',');
getline(ss, description, ',');
getline(ss, prereq, ',');
getline(ss, prereqFeat, ',');
getline(ss, benefit, ',');
getline(ss, normal, ',');
getline(ss, special, ',');
getline(ss, source, ',');
getline(ss, fulltext, ',');
string temp;
getline(ss, temp, ',');
teamwork = stringToBool(temp);
getline(ss, temp, ',');
critical = stringToBool(temp);
getline(ss, temp, ',');
grit = stringToBool(temp);
getline(ss, temp, ',');
style = stringToBool(temp);
getline(ss, temp, ',');
performance = stringToBool(temp);
getline(ss, temp, ',');
racial = stringToBool(temp);
getline(ss, temp, ',');
companion = stringToBool(temp);
getline(ss, race, ',');
getline(ss, note, ',');
getline(ss, goal, ',');
getline(ss, completion, ',');
getline(ss, temp, ',');
multiples = stringToBool(temp);
getline(ss, suggestedTraits, ',');
}

void Spells::parseLine(istream& stream) {
    getline(stream, name, ',');
    getline(stream, school, ',');
    getline(stream, subschool, ',');
    getline(stream, descriptor, ',');
    getline(stream, spell_level, ',');
    getline(stream, casting_time, ',');
    getline(stream, components, ',');
    getline(stream, costly_components, ',');
    getline(stream, range, ',');
    getline(stream, area, ',');
    getline(stream, effect, ',');
    getline(stream, targets, ',');
    getline(stream, duration, ',');
    string temp;
    getline(stream, temp, ',');
    dismissible = stringToBool(temp);
    getline(stream, temp, ',');
    shapeable = stringToBool(temp);
    getline(stream, saving_throw, ',');
    getline(stream, spell_resistance, ',');
    getline(stream, description, ',');
    getline(stream, description_formatted, ',');
    getline(stream, source, ',');
    getline(stream, full_text, ',');
    getline(stream, temp, ',');
    verbal = stringToBool(temp);
    getline(stream, temp, ',');
    somatic = stringToBool(temp);
    getline(stream, temp, ',');
    material = stringToBool(temp);
    getline(stream, temp, ',');
    focus = stringToBool(temp);
    getline(stream, temp, ',');
    divine_focus = stringToBool(temp);
    getline(stream, sor, ',');
    getline(stream, wiz, ',');
    getline(stream, cleric, ',');
    getline(stream, druid, ',');
    getline(stream, ranger, ',');
    getline(stream, bard, ',');
    getline(stream, paladin, ',');
    getline(stream, alchemist, ',');
    getline(stream, summoner, ',');
    getline(stream, witch, ',');
    getline(stream, inquisitor, ',');
    getline(stream, oracle, ',');
    getline(stream, antipaladin, ',');
    getline(stream, magus, ',');
    getline(stream, adept, ',');
    getline(stream, deity, ',');
    getline(stream, SLA_Level, ',');
    getline(stream, domain, ',');
    getline(stream, short_description, ',');
    getline(stream, temp, ',');
    acid = stringToBool(temp);
    getline(stream, temp, ',');
    air = stringToBool(temp);
    getline(stream, temp, ',');
    chaotic = stringToBool(temp);
    getline(stream, temp, ',');
    cold = stringToBool(temp);
    getline(stream, temp, ',');
    curse = stringToBool(temp);
    getline(stream, temp, ',');
    darkness = stringToBool(temp);
    getline(stream, temp, ',');
    death = stringToBool(temp);
    getline(stream, temp, ',');
    disease = stringToBool(temp);
    getline(stream, temp, ',');
    earth = stringToBool(temp);
    getline(stream, temp, ',');
    electricity = stringToBool(temp);
    getline(stream, temp, ',');
    emotion = stringToBool(temp);
    getline(stream, temp, ',');
    evil = stringToBool(temp);
    getline(stream, temp, ',');
    fear = stringToBool(temp);
    getline(stream, temp, ',');
    fire = stringToBool(temp);
    getline(stream, temp, ',');
    force = stringToBool(temp);
    getline(stream, temp, ',');
    good = stringToBool(temp);
    getline(stream, temp, ',');
    language_dependent = stringToBool(temp);
    getline(stream, temp, ',');
    lawful = stringToBool(temp);
    getline(stream, temp, ',');
    light = stringToBool(temp);
    getline(stream, temp, ',');
    mind_affecting = stringToBool(temp);
    getline(stream, temp, ',');
    pain = stringToBool(temp);
    getline(stream, temp, ',');
    poison = stringToBool(temp);
    getline(stream, temp, ',');
    shadow = stringToBool(temp);
    getline(stream, temp, ',');
    sonic = stringToBool(temp);
    getline(stream, temp, ',');
    water = stringToBool(temp);
    getline(stream, ruse, ',');
    getline(stream, id, ',');
    getline(stream, material_costs, ',');
    getline(stream, bloodline, ',');
    getline(stream, patron, ',');
    getline(stream, mythic_text, ',');
    getline(stream, augmented, ',');
    getline(stream, temp, ',');
    mythic = stringToBool(temp);
    getline(stream, bloodrager, ',');
    getline(stream, shaman, ',');
    getline(stream, psychic, ',');
    getline(stream, medium, ',');
    getline(stream, mesmerist, ',');
    getline(stream, occultist, ',');
    getline(stream, spiritualist, ',');
    getline(stream, skald, ',');
    getline(stream, investigator, ',');
    getline(stream, hunter, ',');
    getline(stream, haunt_statistics, ',');
    getline(stream, ruse, ',');
    getline(stream, temp, ',');
    draconic = stringToBool(temp);
    getline(stream, temp, ',');
    meditative = stringToBool(temp);
    getline(stream, temp, ',');
    summoner_unchained = stringToBool(temp);
}

template <typename Type>
void TemplateClass<Type>::createExcelFile(const vector<Type>& objVector, const string& outputFileName) {            //was supposed to build into xml, but did not work as intended. will print the intended formatting with the text, but does show formating implementation 
    ofstream excelFile(outputFileName);

    if (!excelFile.is_open()) {
        cout << "Failed to open file: " << outputFileName << endl;
        return;
    }

    excelFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    excelFile << "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n";
    excelFile << " xmlns:o=\"urn:schemas-microsoft-com:office:office\"\n";
    excelFile << " xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n";
    excelFile << " xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n";
    excelFile << " xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n";
    excelFile << " <Worksheet ss:Name=\"Sheet1\">\n";
    //excelFile << "  <Table>\n";

    for (const auto& object : objVector) {
        excelFile << "   <Row>\n";
        for (const auto& attribute : getAttributes(object)) {
            excelFile << "    <Cell><Data ss:Type=\"String\">" << attribute.second << "</Data></Cell>\n";
        }
        excelFile << "   </Row>\n";
    }

    //excelFile << "  </Table>\n";
    excelFile << " </Worksheet>\n";
    excelFile << "</Workbook>\n";

    excelFile.close();

    if (excelFile.fail()) {
        cout << "Error writing to file: " << outputFileName << endl;
    }
}
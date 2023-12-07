#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "utility.h"

using namespace std;

struct feats {
	string name;
	string type;
	string description;
	string prereq;
	string prereqFeat;
	string benefit;
	string normal;
	string special;
	string source;
	string fulltext;
	bool teamwork;
	bool critical;
	bool grit;
	bool style;
	bool performance;
	bool racial;
	bool companion;
	string race;
	string note;
	string goal;
	string completion;
	bool multiples;
	string suggestedTraits;

    void parseLine(istream& ss);
};

struct Spells {
    string name;
    string school;
    string subschool;
    string descriptor;
    string spell_level;
    string casting_time;
    string components;
    string costly_components;
    string range;
    string area;
    string effect;
    string targets;
    string duration;
    bool dismissible;
    bool shapeable;
    string saving_throw;
    string spell_resistance;
    string description;
    string description_formatted;
    string source;
    string full_text;
    bool verbal;
    bool somatic;
    bool material;
    bool focus;
    bool divine_focus;
    string sor;
    string wiz;
    string cleric;
    string druid;
    string ranger;
    string bard;
    string paladin;
    string alchemist;
    string summoner;
    string witch;
    string inquisitor;
    string oracle;
    string antipaladin;
    string magus;
    string adept;
    string deity;
    string SLA_Level;
    string domain;
    string short_description;
    bool acid;
    bool air;
    bool chaotic;
    bool cold;
    bool curse;
    bool darkness;
    bool death;
    bool disease;
    bool earth;
    bool electricity;
    bool emotion;
    bool evil;
    bool fear;
    bool fire;
    bool force;
    bool good;
    bool language_dependent;
    bool lawful;
    bool light;
    bool mind_affecting;
    bool pain;
    bool poison;
    bool shadow;
    bool sonic;
    bool water;
    string linktext;
    string id;
    string material_costs;
    string bloodline;
    string patron;
    string mythic_text;
    string augmented;
    bool mythic;
    string bloodrager;
    string shaman;
    string psychic;
    string medium;
    string mesmerist;
    string occultist;
    string spiritualist;
    string skald;
    string investigator;
    string hunter;
    string haunt_statistics;
    string ruse;
    bool draconic;
    bool meditative;
    bool summoner_unchained;
    void parseLine(istream& stream);
};

template<typename Type>
struct Trait {};

template <typename Type>
vector<pair<string, string>> getAttributes(const Type& object);

template <>
vector<pair<string, string>> getAttributes<feats>(const feats& feats);

template <>
vector<pair<string, string>> getAttributes<Spells>(const Spells& spells);




template <typename Type>
class TemplateClass {
private:
	void clear();
public:
	TemplateClass();
	~TemplateClass();
	vector<Type> parseData();
    void createExcelFile(const vector<Type>& objVector, const string& outputFileName);
};
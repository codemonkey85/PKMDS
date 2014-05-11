#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_sql.h>
#else
#include "../../PKMDS/include/pkmds/pkmds_sql.h"
#endif
string getspeciesnamesql(const int speciesid, const int langid)
{
	ostringstream o;
	o << "SELECT name FROM pokemon_species_names WHERE (pokemon_species_id = "
		<< speciesid << " ) AND (local_language_id = " << langid << ")";
	return o.str();
}
string getmovenamesql(const int moveid, const int langid)
{
	ostringstream o;
	o << "SELECT name FROM move_names WHERE (move_id = "
		<< moveid << ") AND (local_language_id = "
		<< langid << ")";
	return o.str();
}
string getmoveflavortextsql(const uint16 moveid, const int langid, const int versiongroup)
{
	ostringstream o;
	o << "SELECT move_flavor_text.flavor_text FROM moves " <<
		"INNER JOIN move_flavor_text ON moves.id = move_flavor_text.move_id WHERE" <<
		"(move_flavor_text.language_id = " << langid << ")" <<
		"AND (move_flavor_text.move_id = " << moveid << ")" <<
		"AND (move_flavor_text.version_group_id = " << versiongroup << ")";
	return o.str();
}
string getmovetypenamesql(const uint16 moveid, const int langid)
{
	ostringstream o;
	o << "SELECT type_names.name "
		<< "FROM   moves "
		<< "       INNER JOIN type_names "
		<< "               ON moves.type_id = type_names.type_id "
		<< "       INNER JOIN types "
		<< "               ON moves.type_id = types.id "
		<< "                  AND type_names.type_id = types.id "
		<< "WHERE  ( moves.id = " << moveid << " ) "
		<< "       AND ( type_names.local_language_id = " << langid << " ) ";
	return o.str();
}
string getmovedamagetypenamesql(const uint16 moveid, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT move_damage_class_prose.name "
		<< "FROM   moves "
		<< "       INNER JOIN move_damage_classes "
		<< "               ON moves.damage_class_id = move_damage_classes.id "
		<< "       INNER JOIN move_damage_class_prose "
		<< "               ON move_damage_classes.id = "
		<< "                  move_damage_class_prose.move_damage_class_id "
		<< "WHERE  ( moves.id = " << moveid << " ) "
		<< "       AND ( move_damage_class_prose.local_language_id = " << langid << " ) ";
	return o.str();
}
string getpkmlevelsql(const int id, const int exp)
{
	ostringstream o;
	o << ""
		<< "SELECT experience.level "
		<< "FROM   experience "
		<< "       INNER JOIN pokemon_species "
		<< "               ON experience.growth_rate_id = pokemon_species.growth_rate_id "
		<< "                  AND experience.growth_rate_id = pokemon_species.growth_rate_id "
		<< "WHERE  ( experience.experience <= " << exp << " ) "
		<< "       AND ( pokemon_species.id = " << id << " ) "
		<< "ORDER  BY experience.level DESC ";
	return o.str();
}
string getpkmexptonextsql(const int id, const int exp)
{
	ostringstream o;
	o << ""
		<< "SELECT experience.experience "
		<< "FROM   pokemon_species "
		<< "       INNER JOIN experience "
		<< "               ON pokemon_species.growth_rate_id = experience.growth_rate_id "
		<< "WHERE  ( pokemon_species.id = " << id << " ) "
		<< "       AND ( experience.experience > " << exp << " ) "
		<< "ORDER  BY experience.experience ";
	return o.str();
}
string getpkmexpatcursql(const int id, const int exp)
{
	ostringstream o;
	o << ""
		<< "SELECT experience.experience "
		<< "FROM   pokemon_species "
		<< "       INNER JOIN experience "
		<< "               ON pokemon_species.growth_rate_id = experience.growth_rate_id "
		<< "WHERE  ( pokemon_species.id = " << id << " ) "
		<< "       AND ( experience.level = " << getpkmlevel(id,exp) << " ) "
		<< "ORDER  BY experience.experience ";
	return o.str();
}
string getpkmexpatlevelsql(const int id, const int level)
{
	ostringstream o;
	o << ""
		<< "SELECT experience.experience "
		<< "FROM   pokemon_species "
		<< " INNER JOIN experience "
		<< " ON pokemon_species.growth_rate_id = experience.growth_rate_id "
		<< "WHERE  ( pokemon_species.id = " << id << " ) "
		<< " AND ( experience.level = " << level << " ) "
		<< "ORDER  BY experience.experience";
	return o.str();
}
string getpkmexpatlevelsql(const Species::species id, const int level)
{
	ostringstream o;
	o << ""
		<< "SELECT experience.experience "
		<< "FROM pokemon_species "
		<< " INNER JOIN experience "
		<< " ON pokemon_species.growth_rate_id = experience.growth_rate_id "
		<< "WHERE  ( pokemon_species.id = " << (int)id << " ) "
		<< " AND ( experience.level = " << level << " ) "
		<< "ORDER  BY experience.experience";
	return o.str();
}
string getnaturenamesql(const int natureid, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT name "
		<< "FROM   nature_names "
		<< "WHERE  ( nature_id = " << (int)(natureconvert[natureid][1]) << " ) "
		<< "       AND ( local_language_id = " << langid << " ) ";
	return o.str();
}
string getnatureincreasesql(const int natureid)
{
	ostringstream o;
	o << ""
		<< "SELECT increased_stat_id "
		<< "FROM   natures "
		<< "WHERE  ( id = " << (int)(natureconvert[natureid][1]) << " ) ";
	return o.str();
}
string getnaturedecreasesql(const int natureid)
{
	ostringstream o;
	o << ""
		<< "SELECT decreased_stat_id "
		<< "FROM   natures "
		<< "WHERE  ( id = " << (int)(natureconvert[natureid][1]) << " ) ";
	return o.str();
}
string lookupitemnamesql(const int itemid, const int generation, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT item_names.name "
		<< "FROM   item_game_indices "
		<< "       INNER JOIN item_names "
		<< "               ON item_game_indices.item_id = item_names.item_id "
		<< "WHERE  ( item_game_indices.generation_id = " << generation << " ) "
		<< "       AND ( item_game_indices.game_index = " << itemid << " ) "
		<< "       AND ( item_names.local_language_id = " << langid << " ) ";
	return o.str();
}
string getpkmstatsql(const pokemon_obj &pkm, const Stat_IDs::stat_ids stat_id)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon_stats.base_stat "
		<< "FROM   pokemon_stats "
		<< "INNER JOIN pokemon_forms "
		<< " ON pokemon_stats.pokemon_id = pokemon_forms.pokemon_id "
		<< "INNER JOIN stats "
		<< " ON pokemon_stats.stat_id = stats.id "
		<< "INNER JOIN stat_names "
		<< " ON stats.id = stat_names.stat_id "
		<< "INNER JOIN pokemon_species_names "
		<< " ON stat_names.local_language_id = "
		<< " pokemon_species_names.local_language_id "
		<< "INNER JOIN pokemon "
		<< " ON pokemon_stats.pokemon_id = pokemon.id "
		<< " AND pokemon_forms.pokemon_id = pokemon.id "
		<< " AND pokemon_species_names.pokemon_species_id = "
		<< " pokemon.species_id "
		<< "WHERE  ( pokemon_species_names.local_language_id = 9 ) "
		<< "AND ( stat_names.local_language_id = 9 ) "
		<< "AND ( pokemon_species_names.pokemon_species_id = " << (int)pkm.species_int << " ) ";
	if(getpkmformname(pkm) != "")
	{
		o << "AND ( pokemon_forms.form_order = " << (int)pkm.form_int << " + 1 ) ";
	}
	o << "AND ( stat_names.stat_id = " << (int)stat_id << " ) ";
	return o.str();
}
string getpkmstatsql(const pokemon_obj *pkm, const Stat_IDs::stat_ids stat_id)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon_stats.base_stat "
		<< "FROM   pokemon_stats "
		<< "INNER JOIN pokemon_forms "
		<< " ON pokemon_stats.pokemon_id = pokemon_forms.pokemon_id "
		<< "INNER JOIN stats "
		<< " ON pokemon_stats.stat_id = stats.id "
		<< "INNER JOIN stat_names "
		<< " ON stats.id = stat_names.stat_id "
		<< "INNER JOIN pokemon_species_names "
		<< " ON stat_names.local_language_id = "
		<< " pokemon_species_names.local_language_id "
		<< "INNER JOIN pokemon "
		<< " ON pokemon_stats.pokemon_id = pokemon.id "
		<< " AND pokemon_forms.pokemon_id = pokemon.id "
		<< " AND pokemon_species_names.pokemon_species_id = "
		<< " pokemon.species_id "
		<< "WHERE  ( pokemon_species_names.local_language_id = 9 ) "
		<< "AND ( stat_names.local_language_id = 9 ) "
		<< "AND ( pokemon_species_names.pokemon_species_id = " << (int)pkm->species_int << " ) ";
	if(getpkmformname(pkm) != "")
	{
		o << "AND ( pokemon_forms.form_order = " << (int)pkm->form_int << " + 1 ) ";
	}
	o << "AND ( stat_names.stat_id = " << (int)stat_id << " ) ";
	return o.str();
}
string pkmhasgenddiffsql(const int species)
{
	ostringstream o;
	o << ""
		<< "SELECT has_gender_differences "
		<< "FROM   pokemon_species "
		<< "WHERE  ( id = " << (int)species << " ) ";
	return o.str();
}
string lookupabilitynamesql(const int abilityid, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT name "
		<< "FROM   ability_names "
		<< "WHERE  ( local_language_id = " << langid << " ) "
		<< "       AND ( ability_id = " << abilityid << " ) ";
	return o.str();
}
string getpkmformnamesql(const pokemon_obj &pkm, const int generation, const int langid)
{
	return getpkmformnamesql(pkm.species_int,pkm.form_int,generation,langid);
}
string lookuplocnamesql(const int locid, const int gen, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT location_names.name AS [Location Name] "
		<< "FROM   locations "
		<< "       INNER JOIN location_game_indices "
		<< "               ON locations.id = location_game_indices.location_id "
		<< "       INNER JOIN location_names "
		<< "               ON locations.id = location_names.location_id "
		<< "       INNER JOIN generations "
		<< "               ON location_game_indices.generation_id = generations.id "
		<< "WHERE  ( location_names.local_language_id = " << langid << " ) "
		<< "       AND ( generations.id = " << gen << " ) "
		<< "       AND ( location_game_indices.game_index = " << locid << " ) "
		<< "ORDER  BY location_game_indices.game_index ";
	return o.str();
}
string lookupitemflavortextsql(const int itemid, const int generation, const int langid, const int versiongroup)
{
	ostringstream o;
	o << ""
		<< "SELECT item_flavor_text.flavor_text "
		<< "FROM item_flavor_text "
		<< "INNER JOIN item_game_indices "
		<< "ON item_flavor_text.item_id = item_game_indices.item_id "
		<< "INNER JOIN items "
		<< "ON item_flavor_text.item_id = items.id "
		<< "AND item_game_indices.item_id = items.id "
		<< "WHERE (item_flavor_text.language_id =  " << langid << ") "
		<< "AND (item_game_indices.generation_id = " << generation << ") "
		<< "AND (item_game_indices.game_index = " << itemid << ") "
		<< "AND (item_flavor_text.version_group_id = " << versiongroup << ")";
	return o.str();
}
string lookuppkmcolornamesql(const int species, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon_color_names.name "
		<< "FROM   pokemon_colors "
		<< "       INNER JOIN pokemon_color_names "
		<< "               ON pokemon_colors.id = pokemon_color_names.pokemon_color_id "
		<< "       INNER JOIN pokemon_species "
		<< "               ON pokemon_colors.id = pokemon_species.color_id "
		<< "WHERE  ( pokemon_color_names.local_language_id = " << langid << " ) "
		<< "       AND ( pokemon_species.id = " << species << " ) ";
	return o.str();
}
string lookuppkmcoloridsql(const int species)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon_color_names.pokemon_color_id "
		<< "FROM   pokemon_colors "
		<< "       INNER JOIN pokemon_color_names "
		<< "               ON pokemon_colors.id = pokemon_color_names.pokemon_color_id "
		<< "       INNER JOIN pokemon_species "
		<< "               ON pokemon_colors.id = pokemon_species.color_id "
		<< "WHERE  ( pokemon_color_names.local_language_id = 9 ) "
		<< "       AND ( pokemon_species.id = " << species << " ) ";
	return o.str();
}
string lookupabilityflavortextsql(const int abilityid, const int version_group, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT ability_flavor_text.flavor_text "
		<< "FROM   abilities "
		<< "       INNER JOIN ability_flavor_text "
		<< "               ON abilities.id = ability_flavor_text.ability_id "
		<< "       INNER JOIN languages "
		<< "               ON ability_flavor_text.language_id = languages.id "
		<< "WHERE  ( ability_flavor_text.version_group_id = " << version_group << " ) "
		<< "       AND ( ability_flavor_text.language_id = " << langid << " ) "
		<< "       AND ( abilities.id = " << abilityid << " ) ";
	return o.str();
}
string lookupcharacteristicsql(const int statid, const int iv, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT stat_hint_names.message "
		<< "FROM   stat_hints "
		<< "       INNER JOIN stat_hint_names "
		<< "               ON stat_hints.id = stat_hint_names.stat_hint_id "
		<< "WHERE  ( stat_hint_names.local_language_id = " << langid << " ) "
		<< "       AND ( stat_hints.stat_id = " << statid << " ) "
		<< "       AND ( stat_hints.gene_mod_5 = " << (int)(iv % 5) << " ) ";
	return o.str();
}
string lookuptypenamesql(const int type, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT type_names.name "
		<< "FROM   types "
		<< "       INNER JOIN type_names "
		<< "               ON types.id = type_names.type_id "
		<< "WHERE  ( type_names.local_language_id = " << langid << " ) "
		<< "       AND ( types.id = " << (type+1) << " ) ";
	return o.str();
}
void getmovecatsql(ostringstream& o, const Moves::moves moveid)
{
	string catname = "";
	switch((MoveCategories::movecategories)getmovecategory(moveid))
	{
	case MoveCategories::physical:
		catname = "physical";
		break;
	case MoveCategories::special:
		catname = "special";
		break;
	case MoveCategories::other:
		catname = "other";
		break;
	}
	o << "select image from move_categories where (identifier = \"" << catname << "\")";
}
string getmoveppsql(const Moves::moves moveid)
{
	ostringstream o;
	o << ""
		<< "SELECT pp "
		<< "FROM   moves "
		<< "WHERE  ( id = " << (int)moveid << " ) ";
	return o.str();
}
void getspritesql(ostringstream& o, const pokemon_obj & pkm, int generation)
{
	if(bool(pkm.isegg))
	{
		o << "SELECT image FROM front_male_normal_sprites WHERE identifier = 'egg";
		if(pkm.species == Species::manaphy)
		{
			o << "-manaphy";
		}
		o << "'";
		return;
	}
	o
		<< "SELECT pokemon_forms.form_identifier "
		<< "FROM   pokemon_forms "
		<< "       INNER JOIN pokemon_form_generations "
		<< "               ON pokemon_forms.id = pokemon_form_generations.pokemon_form_id "
		<< "       INNER JOIN pokemon "
		<< "               ON pokemon_forms.pokemon_id = pokemon.id "
		<< "WHERE  ( pokemon_form_generations.generation_id = " << generation << " ) "
		<< "       AND ( pokemon.species_id = " << pkm.species_int << " ) "
		<< "       AND ( pokemon_form_generations.game_index = " << pkm.form_int << " ) ";
	//            << "SELECT pokemon_forms.form_identifier "
	//            << "FROM   pokemon_form_names "
	//            << "       INNER JOIN pokemon_forms "
	//            << "               ON pokemon_form_names.pokemon_form_id = pokemon_forms.id "
	//            << "       INNER JOIN pokemon "
	//            << "               ON pokemon_forms.pokemon_id = pokemon.id "
	//            << "WHERE  ( pokemon.species_id = " << (int)(pkm.species) << " ) "
	//            << "       AND ( pokemon_form_names.local_language_id = " << langid << " ) "
	//            << "       AND ( pokemon_forms.form_order = " << (int)(pkm.forms.form) << " + 1 ) ";
	string formid = getastring(o);
	o.str("");
	o.clear();
	o << pkm.species_int;
	if(formid != "")
	{
		o << "-" << formid;
	}
	formid = o.str().c_str();
	string tshiny = "";
	if(getpkmshiny(pkm))
	{
		tshiny = "shiny";
	}
	else
	{
		tshiny = "normal";
	}
	if(pkm.species == Species::keldeo)
	{
		switch(pkm.form_int)
		{
		case 0:
			if(tshiny == "shiny")
			{
				formid = "647-regular";
			}
			else
			{
				formid = "647-ordinary";
			}
			break;
		case 1:
			formid = "647-resolution";
			break;
		}
	}
	o.str("");
	o.clear();
	string tgender = "";
	if((pkmhasgenddiff(pkm) && (calcpkmgender(pkm) == Genders::female)) & (pkm.species != Species::torchic) & (pkm.species != Species::buizel) & (pkm.species != Species::floatzel))
	{
		tgender = "female";
	}
	else
	{
		tgender = "male";
	}
	o << "SELECT image FROM front_" << tgender << "_" << tshiny << "_sprites WHERE (identifier = '" << formid << "')";
}
void getspritesql(ostringstream& o, const pokemon_obj * pkm, int generation)
{
	if(bool(pkm->isegg))
	{
		o << "SELECT image FROM front_male_normal_sprites WHERE identifier = 'egg";
		if(pkm->species == Species::manaphy)
		{
			o << "-manaphy";
		}
		o << "'";
		return;
	}
	o
		<< "SELECT pokemon_forms.form_identifier "
		<< "FROM   pokemon_forms "
		<< "       INNER JOIN pokemon_form_generations "
		<< "               ON pokemon_forms.id = pokemon_form_generations.pokemon_form_id "
		<< "       INNER JOIN pokemon "
		<< "               ON pokemon_forms.pokemon_id = pokemon.id "
		<< "WHERE  ( pokemon_form_generations.generation_id = " << generation << " ) "
		<< "       AND ( pokemon.species_id = " << pkm->species_int << " ) "
		<< "       AND ( pokemon_form_generations.game_index = " << (int)pkm->form_int << " ) ";
	//            << "SELECT pokemon_forms.form_identifier "
	//            << "FROM   pokemon_form_names "
	//            << "       INNER JOIN pokemon_forms "
	//            << "               ON pokemon_form_names.pokemon_form_id = pokemon_forms.id "
	//            << "       INNER JOIN pokemon "
	//            << "               ON pokemon_forms.pokemon_id = pokemon.id "
	//            << "WHERE  ( pokemon.species_id = " << (int)(pkm.species) << " ) "
	//            << "       AND ( pokemon_form_names.local_language_id = " << langid << " ) "
	//            << "       AND ( pokemon_forms.form_order = " << (int)(pkm.forms.form) << " + 1 ) ";
	string formid = getastring(o);
	o.str("");
	o.clear();
	o << pkm->species_int;
	if(formid != "")
	{
		o << "-" << formid;
	}
	formid = o.str().c_str();
	string tshiny = "";
	if(getpkmshiny(pkm))
	{
		tshiny = "shiny";
	}
	else
	{
		tshiny = "normal";
	}
	if(pkm->species == Species::keldeo)
	{
		switch(pkm->form.keldeo_form)
		{
		case Forms::Keldeo::ordinary:
			if(tshiny == "shiny")
			{
				formid = "647-regular";
			}
			else
			{
				formid = "647-ordinary";
			}
			break;
		case Forms::Keldeo::resolute:
			formid = "647-resolution";
			break;
		}
	}
	o.str("");
	o.clear();
	string tgender = "";
	if((pkmhasgenddiff(pkm) && (calcpkmgender(pkm) == Genders::female)) & (pkm->species != Species::torchic) & (pkm->species != Species::buizel) & (pkm->species != Species::floatzel))
	{
		tgender = "female";
	}
	else
	{
		tgender = "male";
	}
	o << "SELECT image FROM front_" << tgender << "_" << tshiny << "_sprites WHERE (identifier = '" << formid << "')";
}
void geticonsql(ostringstream& o, const pokemon_obj & pkm, int generation)
{
	string formid;
	if(pkm.isegg)
	{
		if(pkm.species == Species::manaphy)
		{
			o << "SELECT image FROM icons_male WHERE (identifier = \"egg-manaphy\")"; // It's a Manaphy egg.
		}
		else
		{
			o << "SELECT image FROM icons_male WHERE (identifier = \"egg\")"; // It's as regular egg.
		}
	}
	else
	{
		//        int formint = pkm.forms.form;
		if(pkm.species == Species::arceus)
		{
			//            formint = 0;
			formid = "";
		}
		else
		{
			o
				<< "SELECT pokemon_forms.form_identifier "
				<< "FROM   pokemon_forms "
				<< "       INNER JOIN pokemon_form_generations "
				<< "               ON pokemon_forms.id = pokemon_form_generations.pokemon_form_id "
				<< "       INNER JOIN pokemon "
				<< "               ON pokemon_forms.pokemon_id = pokemon.id "
				<< "WHERE  ( pokemon_form_generations.generation_id = " << generation << " ) "
				<< "       AND ( pokemon.species_id = " << pkm.species_int << " ) "
				<< "       AND ( pokemon_form_generations.game_index = " << pkm.form_int << " ) ";
			//            << "SELECT pokemon_forms.form_identifier "
			//            << "FROM   pokemon_form_names "
			//            << "       INNER JOIN pokemon_forms "
			//            << "               ON pokemon_form_names.pokemon_form_id = pokemon_forms.id "
			//            << "       INNER JOIN pokemon "
			//            << "               ON pokemon_forms.pokemon_id = pokemon.id "
			//            << "WHERE  ( pokemon.species_id = " << (int)(pkm.species) << " ) "
			//            << "       AND ( pokemon_form_names.local_language_id = " << langid << " ) "
			//            << "       AND ( pokemon_forms.form_order = " << (int)(pkm.forms.form) << " + 1 ) ";
			formid = getastring(o);
			o.str("");
			o.clear();
		}
		o << pkm.species_int;
		if(formid != "")
		{
			o << "-" << formid;
		}
		formid = o.str().c_str();
		o.str("");
		o.clear();
		string tgender = "";
		if(((pkm.species == Species::unfezant) | (pkm.species == Species::frillish) | (pkm.species == Species::jellicent)) && (calcpkmgender(pkm) == Genders::female))
		{
			tgender = "fe";
		}
		tgender += "male";
		if(pkm.species == Species::keldeo)
		{
			switch(pkm.form.keldeo_form)
			{
			case Forms::Keldeo::ordinary:
				formid = "647-regular";
				break;
			case Forms::Keldeo::resolute:
				formid = "647-resolution";
				break;
			}
		}
		if((pkm.species == Species::kyurem) && (pkm.form.kyurem_form != Forms::Kyurem::normal))
		{
			if(pkm.form.kyurem_form == Forms::Kyurem::white)
			{
				formid = "646-white";
			}
			else
			{
				formid = "646-black";
			}
		}
		o << "SELECT image FROM icons_" << tgender << " WHERE (identifier = \"" << formid << "\")";
	}
}
void geticonsql(ostringstream& o, const pokemon_obj * pkm, int generation)
{
	string formid;
	if(pkm->isegg)
	{
		if(pkm->species == Species::manaphy)
		{
			o << "SELECT image FROM icons_male WHERE (identifier = \"egg-manaphy\")"; // It's a Manaphy egg.
		}
		else
		{
			o << "SELECT image FROM icons_male WHERE (identifier = \"egg\")"; // It's as regular egg.
		}
	}
	else
	{
		//        int formint = pkm->forms.form;
		if(pkm->species == Species::arceus)
		{
			//            formint = 0;
			formid = "";
		}
		else
		{
			o
				<< "SELECT pokemon_forms.form_identifier "
				<< "FROM   pokemon_forms "
				<< "       INNER JOIN pokemon_form_generations "
				<< "               ON pokemon_forms.id = pokemon_form_generations.pokemon_form_id "
				<< "       INNER JOIN pokemon "
				<< "               ON pokemon_forms.pokemon_id = pokemon.id "
				<< "WHERE  ( pokemon_form_generations.generation_id = " << generation << " ) "
				<< "       AND ( pokemon.species_id = " << pkm->species_int << " ) "
				<< "       AND ( pokemon_form_generations.game_index = " << (int)pkm->form_int << " ) ";
			//            << "SELECT pokemon_forms.form_identifier "
			//            << "FROM   pokemon_form_names "
			//            << "       INNER JOIN pokemon_forms "
			//            << "               ON pokemon_form_names.pokemon_form_id = pokemon_forms.id "
			//            << "       INNER JOIN pokemon "
			//            << "               ON pokemon_forms.pokemon_id = pokemon.id "
			//            << "WHERE  ( pokemon.species_id = " << (int)(pkm.species) << " ) "
			//            << "       AND ( pokemon_form_names.local_language_id = " << langid << " ) "
			//            << "       AND ( pokemon_forms.form_order = " << (int)(pkm.forms.form) << " + 1 ) ";
			formid = getastring(o);
			o.str("");
			o.clear();
		}
		o << pkm->species_int;
		if(formid != "")
		{
			o << "-" << formid;
		}
		formid = o.str().c_str();
		o.str("");
		o.clear();
		string tgender = "";
		if(((pkm->species == Species::unfezant) | (pkm->species == Species::frillish) | (pkm->species == Species::jellicent)) && (calcpkmgender(pkm) == Genders::female))
		{
			tgender = "fe";
		}
		tgender += "male";
		if(pkm->species == Species::keldeo)
		{
			switch(pkm->form.keldeo_form)
			{
			case Forms::Keldeo::ordinary:
				formid = "647-regular";
				break;
			case Forms::Keldeo::resolute:
				formid = "647-resolution";
				break;
			}
		}
		if((pkm->species == Species::kyurem) && (pkm->form.kyurem_form != Forms::Kyurem::normal))
		{
			if(pkm->form.kyurem_form == Forms::Kyurem::white)
			{
				formid = "646-white";
			}
			else
			{
				formid = "646-black";
			}
		}
		o << "SELECT image FROM icons_" << tgender << " WHERE (identifier = \"" << formid << "\")";
	}
}
void gettypesql(ostringstream& o, const Types::types type)
{
	string type_name = lookuptypename((int)type,9);
	type_name[0] = tolower(type_name[0]);
	o << "Select image from types where (identifier = \"" << type_name << "\")";
}
void gettypesql(ostringstream& o, const int type)
{
	string type_name = lookuptypename(type,9);
	type_name[0] = tolower(type_name[0]);
	o << "Select image from types where (identifier = \"" << type_name << "\")";
}
void getwallpapersql(ostringstream& o, const int wallpaper)
{
	o << "Select image from wallpapers where (identifier = " << wallpaper << ")";
}
void getwallpapersql(ostringstream& o, const Wallpapers::wallpapers wallpaper)
{
	o << "Select image from wallpapers where (identifier = " << (int)wallpaper << ")";
}
void getitemsql(ostringstream& itemsql, const uint16 itemid, const int generation)
{
	string identifier = "";
	ostringstream o;
	o << ""
		<< "SELECT items.identifier "
		<< "FROM   items "
		<< "       INNER JOIN item_game_indices "
		<< "               ON items.id = item_game_indices.item_id "
		<< "WHERE  ( item_game_indices.game_index = " << itemid << " ) "
		<< "       AND ( item_game_indices.generation_id = " << generation << ") ";
	identifier = getastring(o);
	itemsql << "select image from items where (identifier = \"" << identifier << "\")";
}
void getmarkingsql(ostringstream& o, const Markings::markings mark, const bool marked)
{
	o << "select image from markings where (identifier = \"" << int(mark) << (int)marked << "\")";
}
void getballsql(ostringstream& o, const Balls::balls ball, const int generation)
{
	getitemsql(o,balltoitem((int)ball),generation);
}string lookuppkmevolvedspeciessql(int speciesid)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon.species_id "
		<< "FROM   pokemon_species "
		<< "       INNER JOIN pokemon "
		<< "               ON pokemon_species.id = pokemon.species_id "
		<< "       INNER JOIN evolution_chains "
		<< "               ON pokemon_species.evolution_chain_id = evolution_chains.id "
		<< "       INNER JOIN pokemon_evolution "
		<< "               ON pokemon_species.id = pokemon_evolution.evolved_species_id "
		<< "WHERE  ( pokemon_species.evolves_from_species_id = " << speciesid << " ) ";
	return o.str();
}
string getsetlevelsql(pokemon_obj &pkm, int level)
{
	if(level > 100)
	{
		level = 100;
	}
	if(level < 1)
	{
		level = 1;
	}
	ostringstream o;
	o << ""
		<< "SELECT experience.experience "
		<< "FROM   pokemon_species "
		<< "       INNER JOIN experience "
		<< "               ON pokemon_species.growth_rate_id = experience.growth_rate_id "
		<< "WHERE  ( pokemon_species.id = " << pkm.species_int << " ) "
		<< "       AND ( experience.level = " << level << " ) "
		<< "ORDER  BY experience.experience ";
	return o.str();
}
string getsetlevelsql(pokemon_obj *pkm, int level)
{
	if(level > 100)
	{
		level = 100;
	}
	if(level < 1)
	{
		level = 1;
	}
	ostringstream o;
	o << ""
		<< "SELECT experience.experience "
		<< "FROM   pokemon_species "
		<< "       INNER JOIN experience "
		<< "               ON pokemon_species.growth_rate_id = experience.growth_rate_id "
		<< "WHERE  ( pokemon_species.id = " << pkm->species_int << " ) "
		<< "       AND ( experience.level = " << level << " ) "
		<< "ORDER  BY experience.experience ";
	return o.str();
}
string getpkmformnamesql(const pokemon_obj *pkm, const int generation, const int langid)
{
	return getpkmformnamesql(pkm->species_int,(int)pkm->form_int,generation,langid);
}
string getpkmformnamesql(const int speciesid, const int formid, const int generation, const int langid)
{
	ostringstream o;
	o << ""
		<< "select pokemon_form_names.form_name "
		<< "from pokemon "
		<< "inner join pokemon_forms on pokemon.id = pokemon_forms.pokemon_id "
		<< "inner join pokemon_form_names on pokemon_forms.id = pokemon_form_names.pokemon_form_id "
		<< "inner join pokemon_form_generations on pokemon_forms.id = pokemon_form_generations.pokemon_form_id "
		<< "where local_language_id = " << langid << " "
		<< "and generation_id = " << generation << " "
		<< "and species_id = " << speciesid << " "
		<< "and game_index = " << formid << " "
		<< "order by pokemon_form_generations.game_index";
	return o.str();
}
string getmachinetypesql(const Items::items itemid, const int generation, const int version_group)
{
	ostringstream o;
	o << ""
		<< "SELECT types.identifier "
		<< "FROM   machines "
		<< "       INNER JOIN moves "
		<< "               ON machines.move_id = moves.id "
		<< "       INNER JOIN item_game_indices "
		<< "               ON machines.item_id = item_game_indices.item_id "
		<< "       INNER JOIN types "
		<< "               ON moves.type_id = types.id "
		<< "WHERE  ( item_game_indices.generation_id = " << generation << " ) "
		<< "       AND ( machines.version_group_id = " << version_group << " ) "
		<< "       AND ( item_game_indices.game_index = " << (int)itemid << " ) ";
	return o.str();
}
string getmachinemovenamesql(const Items::items itemid, const int generation, const int version_group, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT move_names.name "
		<< "FROM machines "
		<< "INNER JOIN moves "
		<< "ON machines.move_id = moves.id "
		<< "INNER JOIN item_game_indices "
		<< "ON machines.item_id = item_game_indices.item_id "
		<< "INNER JOIN move_names "
		<< "ON moves.id = move_names.move_id "
		<< "WHERE (item_game_indices.generation_id = " << generation << ") "
		<< "AND (machines.version_group_id = " << version_group << ") "
		<< "AND (item_game_indices.game_index = " << (int)itemid << ") "
		<< "AND (move_names.local_language_id = " << langid << ")";
	return o.str();
}
string getpokemoncolorstringsql(const Species::species speciesid)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon_colors.identifier "
		<< "FROM   pokemon_colors "
		<< "       INNER JOIN pokemon_species "
		<< "               ON pokemon_colors.id = pokemon_species.color_id "
		<< "WHERE  pokemon_species.id = " << (int)speciesid;
	return o.str();
}
string getpokemoncolorsql(const Species::species speciesid)
{
	ostringstream o;
	o << ""
		<< "SELECT pokemon_colors.id "
		<< "FROM   pokemon_colors "
		<< "       INNER JOIN pokemon_species "
		<< "               ON pokemon_colors.id = pokemon_species.color_id "
		<< "WHERE  pokemon_species.id = " << (int)speciesid;
	return o.str();
}
string getribbonsql(std::string ribbon, bool hoenn)
{
	string s;
	s += "select image from ";
	if(hoenn)
	{
		s += "ribbons_hoenn";
	}
	else
	{
		s += "ribbons_sinnoh";
	}
	s += " where identifier = \"" + ribbon + "\"";
	return s;
}
string getitempocketsql(const Items::items itemid, const int generation)
{
	ostringstream o;
	o << "SELECT item_pockets.id "
		<< "FROM items "
		<< "INNER JOIN item_game_indices "
		<< "ON items.id = item_game_indices.item_id "
		<< "INNER JOIN item_categories "
		<< "ON items.category_id = item_categories.id "
		<< "INNER JOIN item_pockets "
		<< "ON item_categories.pocket_id = item_pockets.id "
		<< "WHERE (item_game_indices.generation_id = " << generation << ") "
		<< "AND (item_game_indices.game_index = " << (int)itemid << ") ";
	return o.str();
}
string getitempocketnamesql(const Items::items itemid, const int generation, const int langid)
{
	ostringstream o;
	o << ""
		<< "SELECT item_pocket_names.name "
		<< "FROM   items "
		<< "INNER JOIN item_game_indices "
		<< "ON items.id = item_game_indices.item_id "
		<< "INNER JOIN item_categories "
		<< "ON items.category_id = item_categories.id "
		<< "INNER JOIN item_pockets "
		<< "ON item_categories.pocket_id = item_pockets.id "
		<< "INNER JOIN item_pocket_names "
		<< "ON item_pockets.id = item_pocket_names.item_pocket_id "
		<< "WHERE (item_game_indices.generation_id = " << generation << ") "
		<< "AND (item_game_indices.game_index = " << int(itemid) << ") "
		<< "AND (item_pocket_names.local_language_id = " << langid << ") ";
	return o.str();
}

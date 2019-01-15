#pragma once 
class vssd_tool {
public:
	static void trim(std::string * s) {

		if (!s->empty())
		{
			s->erase(0, s->find_first_not_of(" "));
			s->erase(s->find_last_not_of(" ") + 1);
		}

	}
	static void trim(std::string & s) {

		if (!s.empty())
		{
			s.erase(0, s.find_first_not_of(" "));
			s.erase(s.find_last_not_of(" ") + 1);
		}

	}
};

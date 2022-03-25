#include "Credit/Credit.h"
#include "Common/Console.h"

#include <vector>
#include <string>

class Credit {
public:
	int creditInit = 0;
	int credit = 0;
	float factor = 0.0f;
	int min = 0;

	int sum = 0;
	int pereplata = 0;

	int mounth = 1;
	std::vector<std::string> log;
	size_t maxLenghtText = 0;
	bool state = true;

	Credit() {}
	Credit(const int _credit, const float _factor, const int _min) : credit(_credit), creditInit(_credit), factor(_factor), min(_min) {}

	bool update() {
		if (credit <= 0) {
			state = false;
			return state;
		}
		
		int tempCredit = credit;
		tempCredit = tempCredit - min;

		if (tempCredit < 0) {
			//min = min + (-tempCredit);
		}
		sum += min;

		int beforeCredit = credit;
		credit -= min;

		std::string text = "[" + std::to_string(mounth) + "]: " + std::to_string(beforeCredit) + " - " + std::to_string(min) + " = " + std::to_string(credit);

		credit = credit + int((float)credit * factor / 100.0f / 12.0f);


		log.push_back(text);

		if (credit <= 0) {
			std::string& text = log[log.size() - 1];
			pereplata = sum - creditInit;
			text += " (" + std::to_string(pereplata) + ')';

			state = false;
			return state;
		}

		++mounth;
		state = true;
		return state;
	}

	void normalize() {
		for (std::string& text : log) {
			maxLenghtText = text.size() > maxLenghtText ? text.size() : maxLenghtText;
		}

		for (std::string& text : log) {
			size_t lenght = text.size();
			if (maxLenghtText > lenght) {
				size_t leftChar = maxLenghtText - lenght;
				for (size_t i = 0; i < leftChar; ++i) {
					text += " ";
				}
			}
		}
	}

	void normalizeVector(const size_t maxSize) {
		size_t size = log.size();
		if (size >= maxSize) {
			return;
		}

		size_t addSize = maxSize - size;
		for (size_t i = 0; i < addSize; ++i) {
			log.push_back(logSpace());
		}
	}

	std::string logSpace() {
		std::string tempText;
		for (size_t i = 0; i < maxLenghtText; ++i) {
			tempText += " ";
		}
		return tempText;
	}
};

int credit() {
	using namespace engine;
	engine::log("START");

	int caseCredit = 4;

	if (caseCredit == 1)
	{
		int cost = 9602011 - 5000000;

		engine::log("cost: 9602011");
		engine::log("all credit: " + std::to_string(cost));

		Credit credit0(540000, 0.0f, 45000);
		Credit credit16(cost - (540000 + 3000000), 15.9f, 37285); // 1062011 на 3 года, 37.285 / мес
		Credit credit6(3000000, 5.85f, 57789); // 5 лет

		bool state = true;
		while (state) {
			static bool addMin0 = false;
			if (!credit0.state && !addMin0) {
				credit16.min += credit0.min;
				addMin0 = true;
			}

			static bool addMin16 = false;
			if (!credit16.state && !addMin16) {
				credit6.min += credit16.min;
				addMin16 = true;
			}

			bool state0 = credit0.update();
			bool state16 = credit16.update();
			bool state6 = credit6.update();

			if (state0 || state16 || state6) {
				state = true;
			}
			else {
				state = false;
			}
		}

		credit0.normalize();
		credit16.normalize();
		credit6.normalize();

		size_t maxSize = credit0.log.size();
		maxSize = credit6.log.size() > maxSize ? credit6.log.size() : maxSize;
		maxSize = credit16.log.size() > maxSize ? credit16.log.size() : maxSize;

		credit0.normalizeVector(maxSize);
		credit6.normalizeVector(maxSize);
		credit16.normalizeVector(maxSize);

		size_t index = 0;
		while (index < credit0.log.size() || index < credit16.log.size() || index < credit6.log.size()) {
			std::string text;
			text += credit0.log[index] + "\t" + credit16.log[index] + "\t" + credit6.log[index];
			++index;

			engine::log(text);
		}

		int pereplate = credit0.pereplata + credit16.pereplata + credit6.pereplata;
		engine::log("Pereplata: " + std::to_string(pereplate));

		int moynthMax = credit0.mounth;
		moynthMax = credit16.mounth > moynthMax ? credit16.mounth : moynthMax;
		moynthMax = credit6.mounth > moynthMax ? credit6.mounth : moynthMax;
		engine::log( "Year: " + std::to_string((float)moynthMax / 12.0f) + " (" + std::to_string(moynthMax) + ")" );

		int payMax = credit0.min;
		payMax = credit16.min > payMax ? credit16.min : payMax;
		payMax = credit6.min > payMax ? credit6.min : payMax;
		engine::log("payMax: " + std::to_string(payMax));
	}

	if (caseCredit == 2)
	{
		int cost = 10128240 - 5000000;

		engine::log("cost: 10128240");
		engine::log("all credit: " + std::to_string(cost));

		Credit credit0(540000, 0.0f, 45000);
		Credit credit16(cost - (540000 + 3000000), 15.9f, 37285); // 1062011 на 3 года, 37.285 / мес
		Credit credit6(3000000, 5.85f, 57789); // 5 лет

		bool state = true;
		while (state) {
			static bool addMin0 = false;
			if (!credit0.state && !addMin0) {
				credit16.min += credit0.min;
				addMin0 = true;
			}

			static bool addMin16 = false;
			if (!credit16.state && !addMin16) {
				credit6.min += credit16.min;
				addMin16 = true;
			}

			bool state0 = credit0.update();
			bool state16 = credit16.update();
			bool state6 = credit6.update();

			if (state0 || state16 || state6) {
				state = true;
			}
			else {
				state = false;
			}
		}

		credit0.normalize();
		credit16.normalize();
		credit6.normalize();

		size_t maxSize = credit0.log.size();
		maxSize = credit6.log.size() > maxSize ? credit6.log.size() : maxSize;
		maxSize = credit16.log.size() > maxSize ? credit16.log.size() : maxSize;

		credit0.normalizeVector(maxSize);
		credit6.normalizeVector(maxSize);
		credit16.normalizeVector(maxSize);

		size_t index = 0;
		while (index < credit0.log.size() || index < credit16.log.size() || index < credit6.log.size()) {
			std::string text;
			text += credit0.log[index] + "\t" + credit16.log[index] + "\t" + credit6.log[index];
			++index;

			engine::log(text);
		}

		int pereplate = credit0.pereplata + credit16.pereplata + credit6.pereplata;
		engine::log("Pereplata: " + std::to_string(pereplate));

		int moynthMax = credit0.mounth;
		moynthMax = credit16.mounth > moynthMax ? credit16.mounth : moynthMax;
		moynthMax = credit6.mounth > moynthMax ? credit6.mounth : moynthMax;
		engine::log("Year: " + std::to_string((float)moynthMax / 12.0f) + " (" + std::to_string(moynthMax) + ")");

		int payMax = credit0.min;
		payMax = credit16.min > payMax ? credit16.min : payMax;
		payMax = credit6.min > payMax ? credit6.min : payMax;
		engine::log("payMax: " + std::to_string(payMax));
	}

	if (caseCredit == 3)
	{
		int cost = 9602011 - 5000000;

		engine::log("cost: 9602011");
		engine::log("all credit: " + std::to_string(cost));

		Credit credit0(540000, 0.0f, 45000);
		Credit credit12((cost - 540000), 12.0f, 95000); // 5 лет

		bool state = true;
		while (state) {
			static bool addMin0 = false;
			if (!credit0.state && !addMin0) {
				credit12.min += credit0.min;
				addMin0 = true;
			}

			bool state0 = credit0.update();
			bool state12 = credit12.update();

			if (state0 || state12) {
				state = true;
			}
			else {
				state = false;
			}
		}

		credit0.normalize();
		credit12.normalize();

		size_t maxSize = credit0.log.size();
		maxSize = credit12.log.size() > maxSize ? credit12.log.size() : maxSize;

		credit0.normalizeVector(maxSize);
		credit12.normalizeVector(maxSize);

		size_t index = 0;
		while (index < credit0.log.size() || index < credit12.log.size()) {
			std::string text;
			text += credit0.log[index] + "\t" + credit12.log[index];
			++index;

			engine::log(text);
		}

		int pereplate = credit0.pereplata +credit12.pereplata;
		engine::log("Pereplata: " + std::to_string(pereplate));

		int moynthMax = credit0.mounth;
		moynthMax = credit12.mounth > moynthMax ? credit12.mounth : moynthMax;
		engine::log("Year: " + std::to_string((float)moynthMax / 12.0f) + " (" + std::to_string(moynthMax) + ")");

		int payMax = credit0.min;
		payMax = credit12.min > payMax ? credit12.min : payMax;
		engine::log("payMax: " + std::to_string(payMax));
	}

	if (caseCredit == 4)
	{
		int cost = 10128240 - 5000000;

		engine::log("cost: 10128240");
		engine::log("all credit: " + std::to_string(cost));

		Credit credit0(540000, 0.0f, 45000);
		Credit credit12((cost - 540000), 12.0f, 95000); // 5 лет

		bool state = true;
		while (state) {
			static bool addMin0 = false;
			if (!credit0.state && !addMin0) {
				credit12.min += credit0.min;
				addMin0 = true;
			}

			bool state0 = credit0.update();
			bool state12 = credit12.update();

			if (state0 || state12) {
				state = true;
			}
			else {
				state = false;
			}
		}

		credit0.normalize();
		credit12.normalize();

		size_t maxSize = credit0.log.size();
		maxSize = credit12.log.size() > maxSize ? credit12.log.size() : maxSize;

		credit0.normalizeVector(maxSize);
		credit12.normalizeVector(maxSize);

		size_t index = 0;
		while (index < credit0.log.size() || index < credit12.log.size()) {
			std::string text;
			text += credit0.log[index] + "\t" + credit12.log[index];
			++index;

			engine::log(text);
		}

		int pereplate = credit0.pereplata + credit12.pereplata;
		engine::log("Pereplata: " + std::to_string(pereplate));

		int moynthMax = credit0.mounth;
		moynthMax = credit12.mounth > moynthMax ? credit12.mounth : moynthMax;
		engine::log("Year: " + std::to_string((float)moynthMax / 12.0f) + " (" + std::to_string(moynthMax) + ")");

		int payMax = credit0.min;
		payMax = credit12.min > payMax ? credit12.min : payMax;
		engine::log("payMax: " + std::to_string(payMax));
	}

	enterText("FINISH, ENTER to close.");
	return 0;
}

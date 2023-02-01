#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

namespace addfun
{
	int WordCounter(std::string start_string);
	void StringSlayer(std::string* wordlist, std::string StartString);
}
namespace ClassAnimatedText
{
	class AnimatedText
	{
	private:

		std::string m_cur_string = "";
		std::string m_my_string = "";
		int m_duration = 0;
		float m_sm_duration;
		int n = addfun::WordCounter(m_my_string);
		std::string* m_words = new std::string[n];
		int m_i = 0;
		sf::Text m_tex;
		sf::Font m_font;

		void Error(int x) { exit(x); }

	public:

		AnimatedText(std::string my_string, int duration)
		{
			m_my_string = my_string;
			m_duration = duration;
			m_sm_duration = round((float(m_duration) / (m_my_string.length())) * 1000000000) / 1000000000;
			
		}
		~AnimatedText()
		{
			delete[] m_words;
		};


		void AnimatedText::SetFonty(const std::string& font_name, sf::Color color, char style, int size)
		{
			m_tex.setString(m_my_string);
			m_font.loadFromFile(font_name);
			m_tex.setFont(m_font);
			m_tex.setFillColor(color);
			if (style == 'i') { m_tex.setStyle(sf::Text::Italic); }
			if (style == 'b') { m_tex.setStyle(sf::Text::Bold); }
			if (style == 'u') { m_tex.setStyle(sf::Text::Underlined);}
			m_tex.setCharacterSize(size);
		}

		sf::Text* GetText() { return &m_tex; }

		std::string GetMyString(){ return m_my_string;}

		
		int Get_I()
		{
			return m_i;
		}



		sf::Text* GetFrame()
		{
			std::string brok = "";
			m_cur_string += m_my_string[m_i];
			m_tex.setString(m_cur_string);
			m_i += 1;
			if (m_i >= m_my_string.length()) {  m_tex.setString(brok); }
			return &m_tex;
		}

		void SleepMode()
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(int(m_sm_duration * 1000000000)));
		}
	};
 


}
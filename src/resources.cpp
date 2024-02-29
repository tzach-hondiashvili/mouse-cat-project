#include <resources.h>

Resources::Resources()
	:m_textures({}), m_gameMusic(sf::Music()), m_charFont(sf::Font()), m_soundFX({})
{

}
std::vector<sf::Texture>&Resources::getAllTextures()
{
	return m_textures;
}

void Resources::fillTextures()
{
	std::vector <std::string> namesTextures = {"a_menubg.png",
											   "b_playbutton-trans.png",
											   "c_quitbutton-trans.png",
											   "d_grass.png", 
											   "e_fence.png", 
											   "f_gate.png",
											   "g_gift.png",
											   "h_key.png", 
											   "i_cheese.png",
											   "j_mouse.png", 
											   "k_cat.png",
											   "l_frame.png",
											   "m_medkit.png",
											   "n_freeze.png",
											   "o_water.png",
											   "p_portal.png",
											   "q_help.png",
											   "r_tutorial.png",
											   "s_+10.png",
	                                           "t_win.png",
											   "u_loss.png"};

	sf::Texture temp;
	for (int i = 0; i < size(namesTextures); i++)
	{
		if (temp.loadFromFile(namesTextures[i]))
		{
			m_textures.push_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << namesTextures[i] << std::endl;
		}
	}
}

sf::Texture* Resources::getTexture(int index)
{
	return  &m_textures[index];
}

sf::Music& Resources::getGameMusic()
{
	return m_gameMusic;
}

void Resources::updateGameMusic()
{
	m_gameMusic.openFromFile("Liquidzz.ogg");
	m_gameMusic.setVolume(10);
}

sf::Music& Resources::getMenuMusic()
{
	return m_menuMusic;
}
void Resources::updateMenuMusic()
{
	m_menuMusic.openFromFile("MemoryBranch.ogg");
	m_menuMusic.setVolume(20);
}

void Resources::updateFont()
{
	m_charFont.loadFromFile("ARCADE_N.TTF");
}
sf::Font* Resources::getFont()
{
	return &m_charFont;
}
void Resources::fillSoundFX()
{
	std::vector <std::string> namesSoundFX = { "cheese_eating.ogg",//0
											   "door_opening.ogg", //1
											   "door_slam.ogg",    //2  
 											   "key_pickup.ogg",   //3
		                                       "medkit_pickup.ogg",//4
										       "water.ogg",        //5
		                                       "portal.ogg",       //6 
		                                       "hit.ogg",          //7
		                                       "freeze.ogg",       //8
											   "+10.ogg",          //9
		                                       "win.ogg",          //10
											   "loss.ogg"          //11
	};
	for(int i=0; i<size(namesSoundFX);i++)
	{
		sf::SoundBuffer temp;
		temp.loadFromFile(namesSoundFX[i]);
		m_soundFX.push_back(temp);
	}
}
std::vector <sf::SoundBuffer>& Resources::getSoundFX() 
{
	return m_soundFX;
}
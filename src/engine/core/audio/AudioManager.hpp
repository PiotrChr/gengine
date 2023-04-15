#pragma once

namespace Gengine {
    class AudioManager
    {
    public:
        AudioManager() {};
        ~AudioManager() {};
        void init();
        void playMusic();
        void stopMusic();
        void playSound();
        void stopSound();
        void pauseMusic();
        void pauseSound();
        void resumeMusic();
        void resumeSound();
        void setMusicVolume();
        void setSoundVolume();
        void setMusicLoop();
        void setSoundLoop();
        void setMusicPitch();
        void setSoundPitch();
        void setMusicPosition();
        void setSoundPosition();
        void setMusicRelativeToListener();
        void setSoundRelativeToListener();
        void setMusicMinDistance();
        void setSoundMinDistance();
        void setMusicAttenuation();
        void setSoundAttenuation();
        void setMusicPlayingOffset();
        void setSoundPlayingOffset();
        void setMusicChannelCount();
        void setSoundChannelCount();
        void setMusicSampleRate();
        void setSoundSampleRate();
        void setMusicSpatialization();
        void setSoundSpatialization();
        bool isMusic;
        bool isSound;
        int musicVolume;
        int soundVolume;
    private:
        // sf::Music _music;
        // sf::Sound _sound;
        // sf::SoundBuffer _soundBuffer;
    };
}
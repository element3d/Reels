#include "Application.h"
#include <e3/Typography.h>
#include "FrameElement.h"
#include "Timeline.h"
#include "EffectZoomOut.h"
#include "TransitionZoomOut.h"
#include "TransitionZoomIn.h"
#include "TransitionFadeIn.h"
#include "TransitionFadeOut.h"
#include "MediaAnimatedText.h"
#include "MediaCarCard.h"
#include "MediaAnimatedText2.h"
#include "MediaStars.h"
#include "EffectRotation.h"
#include "MediaCarinfoPanel.h"
#include <opencv2/opencv.hpp>
#include "MediaEnginePower.h"
#include "MediaEnding.h"
#include "MediaDwinLogo.h"
#include "MediaEngine.h"
#include <e3/i18n.h>
#include <e3/AssetManager.h>
#include "DBCar.h"
#include "DataManager.h"
#include <SDL2/SDL.h>
#include "CarProject.h"

cv::VideoWriter* video;

void playAudioFromOffset(const char* file, int offsetSeconds) {
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;


	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}

	if (SDL_LoadWAV(file, &wavSpec, &wavBuffer, &wavLength) == NULL) {
		std::cerr << "Failed to load WAV file! SDL Error: " << SDL_GetError() << std::endl;
		return;
	}

	// Calculate the byte offset to start from
	// Assuming the audio format is PCM with 16 bit per sample (2 bytes per sample)
	int bytesPerSample = wavSpec.channels * (SDL_AUDIO_BITSIZE(wavSpec.format) / 8);
	Uint32 offsetBytes = offsetSeconds * wavSpec.freq * bytesPerSample;

	if (offsetBytes >= wavLength) {
		std::cerr << "Offset is beyond the length of the audio file." << std::endl;
		SDL_FreeWAV(wavBuffer);
		return;
	}

	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	if (deviceId == 0) {
		std::cerr << "Failed to open audio device! SDL Error: " << SDL_GetError() << std::endl;
		SDL_FreeWAV(wavBuffer);
		return;
	}

	// Queue only the part of the audio starting from the calculated offset
	SDL_QueueAudio(deviceId, wavBuffer + offsetBytes, wavLength - offsetBytes);
	SDL_PauseAudioDevice(deviceId, 0); // Start playing


}

void playAudio1(const char* file) {
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;

	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}

	if (SDL_LoadWAV(file, &wavSpec, &wavBuffer, &wavLength) == NULL) {
		std::cerr << "Failed to load WAV file! SDL Error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	if (deviceId == 0) {
		std::cerr << "Failed to open audio device! SDL Error: " << SDL_GetError() << std::endl;
		SDL_FreeWAV(wavBuffer);
		return;
	}

	SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0); // Start playing
}

Application::Application(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution)
	: ApplicationBase(applicationName, os, target, windowSize, resolution)
{
	

	e3::i18n::Get()->SetLocale("ru");
	
	//		isPortrait = true;

	e3::Typography::AddFont("facon", e3::EFontStyle::Normal, "RidersReels/fonts/facon.ttf");
	e3::Typography::AddFont("open sans", e3::EFontStyle::Normal, "RidersReels/fonts/OpenSans-Regular.ttf");
	e3::Typography::AddFont("open sans", e3::EFontStyle::Bold, "RidersReels/fonts/OpenSans-Bold.ttf");
	e3::Typography::AddFont("open sans", e3::EFontStyle::SemiBold, "RidersReels/fonts/OpenSans-ExtraBold.ttf");

	DBCar* pCar = DataManager::Get()->GetCar(1138);
	mCarProject = new CarProject();
	PushElement(mCarProject->GetElement());

	

	

	video = new cv::VideoWriter("D://output.avi", cv::VideoWriter::fourcc('M','J','P','G'), 60, cv::Size(GetWindowSize().Width, GetWindowSize().Height));

}

void Application::AnimateElement(e3::Element* e, e3::Element* next)
{
	/*e3::Animation* a = new e3::Animation(e);
	a->Start(0.05, 1.4, 1.1, [e](float v){
		e->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		e->SetRotation(v*10, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	}, [next, e, this](){
		e3::Animation* a = new e3::Animation(e);
		a->Start(4, 1.1, 1, [e](float v){
			e->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
			e->SetRotation(v*10, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
		}, [next,e, this](){
			if (next) 
			{
				mLayer1Element->RemoveElement(e);
				mLayer1Element->AddElement(next);
				AnimateElement(next, nullptr);
			}
		});
	});*/
}


void Application::OnResize(float width, float height)
{

}

    // Set the desired frame rate for the video
    const int videoFrameRate = 60;
    const double frameDuration = 1.0 / videoFrameRate;
    auto nextFrameTime = std::chrono::steady_clock::now() + std::chrono::duration<double>(frameDuration);
	    auto lastFrameTime = std::chrono::steady_clock::now();

void Application::Render()
{
        auto start = std::chrono::steady_clock::now();

	if (mFirstFrame) 
	{
		// mFirstFrame = false;
		Timeline::Get()->Begin();
		// playAudioFromOffset("riders.wav", 50);
	}
	Timeline::Get()->OnFrame();
	long time = Timeline::Get()->GetTime();
	

	mCarProject->Render();
	e3::Application::Render();
	mFirstFrame = false;

	return;
	if (time > 22000)  {

		video->release();
		return;
	}
//	return;
	e3::Image* pI = RenderToImage();
	void* pData = pI->GetData();
	int w = pI->GetWidth();
	int h = pI->GetHeight();
	int c = pI->GetNumChannels();

	 cv::Mat img;
    if (c == 3) {
        img = cv::Mat(h, w, CV_8UC3, pData);
    } else if (c == 4) {
        img = cv::Mat(h, w, CV_8UC4, pData);
    } else {
        // Handle other cases if necessary
        std::cerr << "Unsupported number of channels: " << c << std::endl;
        return;
    }

    // Convert from BGRA to BGR if necessary
  //  if (c == 4) {
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    //}
	//cv::imwrite("a.jpg", img);
	      //  video->write(img);

     auto renderEnd = std::chrono::steady_clock::now();

        // Check if enough time has passed to write the next frame
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = now - lastFrameTime;

        if (elapsedTime.count() >= frameDuration) {
            // Write the frame into the video file
			if (!mFirstFrame) video->write(img);
            lastFrameTime = now; // Update last frame time
        }

        auto writeEnd = std::chrono::steady_clock::now();

        // Print profiling information
        std::chrono::duration<double> renderTime = renderEnd - start;
        std::chrono::duration<double> writeTime = writeEnd - renderEnd;
		mFirstFrame = false;
}

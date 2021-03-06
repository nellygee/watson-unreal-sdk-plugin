#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Json.h"
#include "Common/Authorization.h"
#include "Common/Configuration.h"
#include "RecognizeDataModel.h"
#include "SpeechToText.generated.h"



UCLASS()
class WATSONSDK_API USpeechToText : public UObject
{
	GENERATED_BODY()

public:
	FAuthorization Authorization;
	FConfiguration Configuration;
	USpeechToText();

	//////////////////////////////////////////////////////////////////////////
	// Sessionless Recognize Audio

private:
	TMap<TSharedPtr<IHttpRequest>, TSharedPtr<FSpeechToTextRecognizeDelegate>> PendingRecognizeRequests;
	void OnRecognizeComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

public:
	/**
	 * Sends audio and returns transcription results for a sessionless recognition request.
	 *
	 * @param AudioData		The raw audio to be transcribed
	 * @param AudioModel	The identifier of the model to be used for the recognition request
	 * @return				Delegate called when the request is complete.
	 */
	TSharedPtr<FSpeechToTextRecognizeDelegate> Recognize(TArray<uint8> AudioData, const FString& AudioModel);

};

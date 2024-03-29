/*
  ==============================================================================

    Oscillator.h
    Created: 17 Oct 2019 6:07:00pm
    Author:  Andre

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator : public Component,
	private ComboBox::Listener
{
public:
	Oscillator(JuceSynthFrameworkAudioProcessor&);
	~Oscillator();

	void paint(Graphics&) override;
	void resized() override;

	void comboBoxChanged(ComboBox*) override;

private:
	ComboBox oscMenu;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	JuceSynthFrameworkAudioProcessor& processor;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator)
};

/*
  ==============================================================================

    Oscillator.cpp
    Created: 17 Oct 2019 6:07:00pm
    Author:  Andre

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(JuceSynthFrameworkAudioProcessor& p) :
	processor(p)
{
	setSize(200, 200);

	oscMenu.addItem("Sine", 1);
	oscMenu.addItem("Saw", 2);
	oscMenu.addItem("Square", 3);
	oscMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscMenu);
	oscMenu.addListener(this);

	waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint(Graphics& g)
{
	//background stuff
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

	g.fillAll(Colours::black);
	g.setColour(Colours::white);
	g.drawText("Oscillator One", titleArea, Justification::centredTop);


	juce::Rectangle <float> area(25, 25, 150, 150);

	g.setColour(Colours::yellow);
	g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Oscillator::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(40);
	oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator::comboBoxChanged(ComboBox* box)
{

}


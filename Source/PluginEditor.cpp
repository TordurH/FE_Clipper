/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ClipperAudioProcessorEditor::ClipperAudioProcessorEditor (ClipperAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    knobAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "GAIN", knob);
    hardclipAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "HARDCLIP", hardclip);

    knob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    knob.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&knob);

    hardclip.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    hardclip.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&hardclip);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ClipperAudioProcessorEditor::~ClipperAudioProcessorEditor()
{
}

//==============================================================================
void ClipperAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void ClipperAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto bounds = getLocalBounds();

    knob.setBounds(0, 0, bounds.getWidth()/2, bounds.getHeight());
    hardclip.setBounds(bounds.getWidth()/2, 0, bounds.getWidth() / 2, bounds.getHeight());

}

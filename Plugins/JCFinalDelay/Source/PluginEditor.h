/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SliderContainer.h"
#include "MyLookAndFeel.h"
#include "TopRow.h"
#include "BottomRow.h"
#include "MiddleRow.h"

//==============================================================================
/**
*/
class Week6AssignmentAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                             public juce::DragAndDropContainer,
                                             public juce::ComponentDragger,
                                             public juce::ComponentBoundsConstrainer
{
public:
    Week6AssignmentAudioProcessorEditor (Week6AssignmentAudioProcessor&);
    ~Week6AssignmentAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<BottomRow> mBottomRow;
    std::unique_ptr<TopRow> mTopRow;
    std::unique_ptr<MiddleRow> mMiddleRow;
    std::unique_ptr<MyLookAndFeel> mLookAndFeel;
    juce::OwnedArray<SliderContainer> mSliderContainers;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Week6AssignmentAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Week6AssignmentAudioProcessorEditor)
};

/*
  ==============================================================================

    DraggableButton.cpp
    Created: 8 Apr 2023 9:21:19pm
    Author:  程

  ==============================================================================
*/

#include "JuceHeader.h"
#include "DraggableButton.h"

DraggableButton::DraggableButton()
{
}

DraggableButton::~DraggableButton()
{
}

void DraggableButton::paint (juce::Graphics& g)
{
    g.setColour (juce::Colour(8, 143, 173));
    g.fillEllipse (0, 0, getWidth(), getHeight());
    g.setColour (getColour());
    g.fillEllipse (getWidth() / 5.0f, getHeight() / 5.0f, getWidth() / 5.0f * 3, getHeight() / 5.0f * 3);
}

void DraggableButton::resized()
{
    
}

void DraggableButton::mouseEnter(const juce::MouseEvent& event)
{
    isEntered = true;
}

void DraggableButton::mouseExit(const juce::MouseEvent& event)
{
    isEntered = false;
}

juce::Colour DraggableButton::getColour()
{
    if(isEntered){
        return juce::Colours::hotpink.brighter();
    } else{
        return juce::Colours::hotpink;
    }
}

void DraggableButton::mouseDown (const juce::MouseEvent& e)
{
    
    juce::ComponentDragger::startDraggingComponent(this, e);
    
    
}

void DraggableButton::mouseDrag (const juce::MouseEvent& e)
{
    juce::ComponentBoundsConstrainer constrainer;
    constrainer.setMinimumOnscreenAmounts(200, 200, 200, 200);
    juce::ComponentDragger::dragComponent(this, e, &constrainer);
    onDrag();
}

void DraggableButton::setState (const bool state)
{
    mState = state;
}

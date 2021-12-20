#include "Harmonist.h"

Harmonist::Harmonist(string text)
{
    _text = text;
}

string Harmonist::GetText()
{
    return _text;
}

void Harmonist::SetText(string text)
{
    _text = text;
}

#include "PokerScore.h"

const std::string PokerScore::SCORES_STR[] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush",
"Straight", "Three of a Kind", "Two Pair", "One Pair", "High Card"};

PokerScore::PokerScore() = default;

void PokerScore::operator += (PokerScore::Scores score)
{
    this->_scores.push_back(score);
}

PokerScore& PokerScore::operator = (const PokerScore& p)
{
    if (&p != this)
    {
        this->_scores = p._scores;
    }
    return *this;
}

PokerScore::Scores PokerScore::operator[](unsigned int index)
{
    return this->_scores.at(index);
}

std::ostream& operator << (std::ostream& out, const PokerScore& pokerScores)
{
    for (const PokerScore::Scores& score : pokerScores._scores)
    {
        out << PokerScore::SCORES_STR[score] << "\n";
    }
    return out;
}

std::string PokerScore::toString()
{
    std::string pokerScore;
    for (int i = 0; i < size(); ++i)
    {
        pokerScore += SCORES_STR[this->_scores.at(i)];
        if (i != size() - 1)
        {
            pokerScore += ", ";
        }
    }
    return pokerScore;
}


int PokerScore::size()
{
    return int(this->_scores.size());
}


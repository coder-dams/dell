#include <string>
#include "../client.h"
#include "../../shared/state.h"
#include "../../shared/engine.h"
#include <iostream>
#include <unistd.h>

using namespace client;
using namespace state;
using namespace engine;
using namespace std;

bool KeyboardListener::triggerAction(engine::Engine &engine, KeyID key)
{
    int actualPlayer = engine.currentState.getTurnOwner();

    switch (key)
    {
    case LEFT:
    {
        if (engine.currentState.currentFightAction == F_IDLE)
        {
            vector<unique_ptr<Character>> chars;
            for (auto &charac : engine.currentState.getCharacters())
            {
                if (charac->getPlayerOwner() == actualPlayer  && charac->getStatus() != DEAD)
                {
                    unique_ptr<Character> ptr_c(new Character(*charac));
                    chars.push_back(move(ptr_c));
                }
            }
            engine.currentState.getCursor().move(chars.front()->position);
            chars.clear();
        }
        else
            engine.currentState.getCursor().getPosition().setX(engine.currentState.getCursor().getPosition().getX() - 1);
        //StateEvent se{StateEventID::CURSOR_CHANGED};
        //engine.currentState.notifyObservers(se, engine.currentState);
        break;
    }
    case RIGHT:
    {
        if (engine.currentState.currentFightAction == F_IDLE)
        {
            vector<unique_ptr<Character>> chars;
            for (auto &charac : engine.currentState.getCharacters())
            {
                if (charac->getPlayerOwner() == actualPlayer && charac->getStatus() != DEAD)
                {
                    unique_ptr<Character> ptr_c(new Character(*charac));
                    chars.push_back(move(ptr_c));
                }
            }
            engine.currentState.getCursor().move(chars.front()->position);
            chars.clear();
        }
        else
            engine.currentState.getCursor().getPosition().setX(engine.currentState.getCursor().getPosition().getX() + 1);
        //StateEvent se{StateEventID::CURSOR_CHANGED};
        //engine.currentState.notifyObservers(se, engine.currentState);
        break;
    }
    case TOP:
    {
        if (engine.currentState.currentFightAction == F_IDLE)
        {
            vector<unique_ptr<Character>> chars;
            for (auto &charac : engine.currentState.getCharacters())
            {
                if (charac->getPlayerOwner() == actualPlayer && charac->getStatus() != DEAD)
                {
                    unique_ptr<Character> ptr_c(new Character(*charac));
                    chars.push_back(move(ptr_c));
                }
            }
            engine.currentState.getCursor().move(chars.front()->position);
            chars.clear();
        }
        else
            engine.currentState.getCursor().getPosition().setY(engine.currentState.getCursor().getPosition().getY() - 1);
        //StateEvent se{StateEventID::CURSOR_CHANGED};
        //engine.currentState.notifyObservers(se, engine.currentState);
        break;
    }
    case DOWN:
    {
        if (engine.currentState.currentFightAction == F_IDLE)
        {
            vector<unique_ptr<Character>> chars;
            for (auto &charac : engine.currentState.getCharacters())
            {
                if (charac->getPlayerOwner() == actualPlayer && charac->getStatus() != DEAD)
                {
                    unique_ptr<Character> ptr_c(new Character(*charac));
                    chars.push_back(move(ptr_c));
                }
            }
            engine.currentState.getCursor().move(chars.front()->position);
            chars.clear();
        }
        else
            engine.currentState.getCursor().getPosition().setY(engine.currentState.getCursor().getPosition().getY() + 1);
        //StateEvent se{StateEventID::CURSOR_CHANGED};
        //engine.currentState.notifyObservers(se, engine.currentState);
        break;
    }
    case ATK: 
    {
        if (engine.currentState.currentFightAction == F_IDLE || engine.currentState.currentFightAction == F_MOVING)
        {
            engine.currentState.setFightAction(ATTACKING);
            //engine.currentState.getCursor().setVisible(true);
            //engine.currentState.getCursor().setTileCode(1);
            //StateEvent se{StateEventID::CURSOR_CHANGED};
            //engine.currentState.notifyObservers(se, engine.currentState);
        }
        break;
    }
    case PASS:
    {
        std::unique_ptr<engine::Command> ptr_fc(new engine::SwitchTurnCommand());
        engine.addCommand(move(ptr_fc));
        engine.init();
        break;
    }
    
    default:
        break;

    return true;
    }
}


//
// Created by sudhs on 26/01/2026.
//

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}// Questo metodo verrà chiamato dal Timer ogni volta che scatta un secondo
    virtual void update() = 0;
};

#endif
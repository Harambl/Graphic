#ifndef COMMAND_H
#define COMMAND_H
#pragma once

class Command
{
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
    virtual void undo() = 0;

};

#endif // COMMAND_H

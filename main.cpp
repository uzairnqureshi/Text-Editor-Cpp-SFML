#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

#define MAX 100 

class CharStack {
private:
    char stack[MAX];
    int top;

public:
    CharStack() { top = -1; }

    void push(char character) {
        if (top >= MAX - 1) return;
        stack[++top] = character;
    }

    char pop() {
        if (top < 0) return 0;
        return stack[top--];
    }

    void clear() {
        top = -1;
    }

    string toString() {
        if (top < 0) return "";
        return string(stack, top + 1);
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top >= MAX - 1; }
};

int main() {
    RenderWindow window(VideoMode({ 800, 600 }), "Commitment Issues :)");
    window.setFramerateLimit(60);

    Font font;
    if (!font.openFromFile("C:/Windows/Fonts/ariblk.ttf")) {
        cerr << "Error: Could not load font 'ariblk.ttf'." << endl;
        return -1;
    }

    Text displayText(font);
    displayText.setCharacterSize(24);
    displayText.setFillColor(Color::White);
    displayText.setPosition({ 50, 50 });

    Text instructions(font);
    instructions.setString("The Text Editor");
    instructions.setCharacterSize(18);
    instructions.setFillColor(Color(150, 150, 150));
    instructions.setPosition({ 50, 500 });

    CharStack mainStack;
    CharStack redoStack;

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }

            else if (const auto* keyEvent = event->getIf<Event::KeyPressed>()) {

                bool ctrlPressed = Keyboard::isKeyPressed(Keyboard::Key::LControl) ||
                    Keyboard::isKeyPressed(Keyboard::Key::RControl);

                if (keyEvent->code == Keyboard::Key::Escape) {
                    window.close();
                }

                else if (keyEvent->code == Keyboard::Key::Backspace) {
                    if (!mainStack.isEmpty()) {
                        mainStack.pop();
                        redoStack.clear();
                    }
                }

                else if (ctrlPressed && keyEvent->code == Keyboard::Key::Z) {
                    if (!mainStack.isEmpty()) {
                        char c = mainStack.pop();
                        redoStack.push(c);
                    }
                }

                else if (ctrlPressed && keyEvent->code == Keyboard::Key::Y) {
                    if (!redoStack.isEmpty()) {
                        char c = redoStack.pop();
                        mainStack.push(c);
                    }
                }
            }

            else if (const auto* textEvent = event->getIf<Event::TextEntered>()) {
                char32_t unicode = textEvent->unicode;

                if (unicode >= 32 && unicode < 128) {
                    mainStack.push(static_cast<char>(unicode));

                    redoStack.clear();
                }
            }
        }

        string currentContent = mainStack.toString();

        static Clock cursorClock;
        if (cursorClock.getElapsedTime().asSeconds() < 0.5f) {
            displayText.setString(currentContent + "_");
        }
        else {
            displayText.setString(currentContent);
        }
        if (cursorClock.getElapsedTime().asSeconds() > 1.0f) {
            cursorClock.restart();
        }

        window.clear(Color(30, 30, 30));
        window.draw(instructions);
        window.draw(displayText);
        window.display();
    }

    return 0;
}

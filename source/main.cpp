#include "Application.h"

#include "Utils.h"
#include <thread>

bool isRunning{ true };

void Update(Application& app)
{
    while (isRunning)
    {
        app.Update();
    }
}

void Draw(RenderWindow& window, Application& app)
{
    while (isRunning)
    {
        window.clear(Color::White);
        app.Draw(window);
        window.display();
    }
}

int main()
{
    Application app;

    RenderWindow window(VideoMode(800, 800), "AIDots");
    window.setActive(false);

    thread drawThread(Draw, ref(window), ref(app));
    thread updateThread(Update, ref(app));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                isRunning = false;
            }
        }
    }

    updateThread.join();
    drawThread.join();

    return 0;
}

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A,
	Keyboard::Z,
	Keyboard::Up,
	Keyboard::Down
};
const Vector2f paddleSize(25.0f, 100.0f);
const float ballRadius = 10.0f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.0f;
Vector2f ballVelocity;
bool server = false;
Font font;
Text text;
int p1Score, p2Score;

CircleShape ball;
RectangleShape paddles[2];

void Reset();

void Load()
{
	// Set size and origin of paddles
	for (auto& p : paddles)
	{
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.0f);
	}

	//Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);

	//Load font-face from res dir
	font.loadFromFile("res/fonts/PixelFont.ttf");
	//Set text element to use font
	text.setFont(font);
	//Set the character size to 24 pixels
	text.setCharacterSize(36);
	//Set text color
	text.setColor(Color::White);

	Reset();

}

void Update(RenderWindow& window)
{
	//Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();

	//Check and consume events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	//Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}

	//Handle paddle movement
	float direction1 = 0.0f;

	if (Keyboard::isKeyPressed(controls[0]))
	{
		direction1--;
	}
	else if (Keyboard::isKeyPressed(controls[1]))
	{
		direction1++;
	}
	paddles[0].move(0, direction1 * paddleSpeed * dt);

	float direction2 = 0.0f;
	/*if (Keyboard::isKeyPressed(controls[2]))
	{
		direction2--;
	}
	else if (Keyboard::isKeyPressed(controls[3]))
	{
		direction2++;
	}
	paddles[1].move(0, direction2 * paddleSpeed * dt);*/

	if (ball.getPosition().y > paddles[1].getPosition().y)
	{
		direction2++;
	}
	else if (ball.getPosition().y < paddles[1].getPosition().y)
	{
		direction2--;
	}
	paddles[1].move(0, direction2 * paddleSpeed * dt);

	ball.move(ballVelocity * dt);

	//Check ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight)
	{
		//Bottom Wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (by < 0)
	{
		//Top Wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, 10);
	}
	else if (bx > gameWidth)
	{
		//Right side
		server = true;
		Reset();
		p1Score++; 
		text.setString(to_string(p1Score) + " - " + to_string(p2Score));
	}
	else if (bx < 0)
	{
		//Left side
		server = false;
		Reset();
		p2Score++;
		text.setString(to_string(p1Score) + " - " + to_string(p2Score));
	}
	else if (bx < paddleSize.x &&
		by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
		by < paddles[0].getPosition().y + (paddleSize.y * 0.5))
	{
		//Left Paddle
		ballVelocity.x *= -1.1f;
		ballVelocity.y *= 1.1f;
		ball.move(paddleSize.x / 2, 0);
	}
	else if (bx > gameWidth - paddleSize.x &&
		by > paddles[1].getPosition().y - (paddleSize.y * 0.5) &&
		by < paddles[1].getPosition().y + (paddleSize.y * 0.5))
	{
		//Right Paddle
		ballVelocity.x *= -1.1f;
		ballVelocity.y *= 1.1f;
		ball.move(-paddleSize.x / 2, 0);
	}

	for (int i = 0; i < 2; i++)
	{
		if (paddles[i].getPosition().y + (paddleSize.y * 0.5) > gameHeight)
		{
			paddles[i].setPosition(paddles[i].getPosition().x, gameHeight - (paddleSize.y / 2));
		}
		if (paddles[i].getPosition().y - (paddleSize.y * 0.5) < 0)
		{
			paddles[i].setPosition(paddles[i].getPosition().x, paddleSize.y / 2);
		}
	}
}

void Render(RenderWindow& window)
{
	//Draw Everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
	window.draw(text);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while(window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}

	return 0;
}

void Reset()
{
	//Reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - (10 + paddleSize.x / 2), gameHeight / 2);

	//Reset ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

	p1Score = 0;
	p2Score = 0;

	//Reset score text
	text.setString(to_string(p1Score) + " - " + to_string(p2Score));
	//Set score text position
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}
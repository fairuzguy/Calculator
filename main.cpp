#include <SFML/Graphics.hpp> //includes SFML libraries
#include <iostream>
#include "BUTTONS.h"
#include <string>


using namespace std;
using namespace sf; //for graphics

int main()
{
    RenderWindow window(VideoMode(900, 700),"Calculatrice");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    srand(time(0));

    /// Font for calculator
    Font f1; /// this font is like courier except better
    cout << f1.loadFromFile("Cousine-Bold.ttf") << endl;

    /// Color base for all the buttons
    Color c; /// fill
    c = Color::Red;
    Color C; /// outline
    C = Color::Magenta;
    Color Cc; /// text
    Cc = Color::White;
    Color Bc; /// background
    Bc = Color::Black;

    float x, y; /// Mouse coordinates
    bool Click = false; /// Mouse click holder

    /// |---------------- Colour buttons ------------------|
    Button Colour(140, 40, 100, 650, c, C);
    bool colour = false;
    Text couleur;
    couleur.setFont(f1);
    couleur.setString("Colour");
    couleur.setCharacterSize(34);
    couleur.setPosition(112, 647);

    /// need a back button, and 9 buttons:
    /// 3 buttons are for each the red, blue, and green sliders for outline, fill, and text

    Button Back(102, 40, 10, 10, c, C);
    bool bak = false;
    Text retourner;
    retourner.setFont(f1);
    retourner.setString("Back");
    retourner.setCharacterSize(37);
    retourner.setPosition(18, 6);

    Text Outline;
    Outline.setFont(f1);
    Outline.setString("Outline");
    Outline.setCharacterSize(37);
    Outline.setPosition(395, 6); /// -44
    Button R1(50, 30, 450 - 256/2 + C.r, 100 -44, c, C); /// These don't need texts
    bool r1 = false;
    Button G1(50, 30, 450 - 256/2 + C.g, 140 -44, c, C); /// These don't need texts
    bool g1 = false;
    Button B1(50, 30, 450 - 256/2 + C.b, 180 -44, c, C); /// These don't need texts
    bool b1 = false;

    Text Fill;
    Fill.setFont(f1);
    Fill.setString("Fill");
    Fill.setCharacterSize(37);
    Fill.setPosition(425, 220-44);
    Button R2(50, 30, 450 - 256/2 + c.r, 270-44, c, C); /// These don't need texts
    bool r2 = false;
    Button G2(50, 30, 450 - 256/2 + c.g, 310-44, c, C); /// These don't need texts
    bool g2 = false;
    Button B2(50, 30, 450 - 256/2 + c.b, 350-44, c, C); /// These don't need texts
    bool b2 = false;

    Text t;
    t.setFont(f1);
    t.setString("Text");
    t.setCharacterSize(37);
    t.setPosition(425, 390-44);
    Button R3(50, 30, 450 - 256/2 + Cc.r, 440-44, c, C); /// These don't need texts
    bool r3 = false;
    Button G3(50, 30, 450 - 256/2 + Cc.g, 480-44, c, C); /// These don't need texts
    bool g3 = false;
    Button B3(50, 30, 450 - 256/2 + Cc.b, 520-44, c, C); /// These don't need texts
    bool b3 = false;

    Text Background;
    Background.setFont(f1);
    Background.setString("Background");
    Background.setCharacterSize(37);
    Background.setPosition(363, 570 -44);
    Button R4(50, 30, 450 - 256/2 + Bc.r, 620-44, c, C);
    bool r4 = false;
    Button G4(50, 30, 450 - 256/2 + Bc.g, 660-44, c, C);
    bool g4 = false;
    Button B4(50, 30, 450 - 256/2 + Bc.b, 700-44, c, C);
    bool b4 = false;

    bool holder1 = false;
    bool holder2 = false;
    bool holder3 = false;
    bool holder4 = false;
    bool holdeg1 = false;
    bool holdeg2 = false;
    bool holdeg3 = false;
    bool holdeg4 = false;
    bool holdeb1 = false;
    bool holdeb2 = false;
    bool holdeb3 = false;
    bool holdeb4 = false;

    float x0;

    /// |--------------------- SETTINGS ------------------------|
    Button Settings(180, 40, 250, 650, c, C);
    bool settings = false;
    Text reglages;
    reglages.setFont(f1);
    reglages.setString("Settings");
    reglages.setCharacterSize(34);
    reglages.setPosition(259, 647);

    /// |----------------------- Number buttons --------------------------|
    Button One(40, 40, 100, 500, c, C);
    bool one = false; /// Holder for 1
    Text un;
    un.setFont(f1);
    un.setString("1");
    un.setCharacterSize(34);
    un.setPosition(111, 497); /// optimal position; 11 right, 3 up of the button itself

    Button Two(40, 40, 150, 500, c, C);
    bool two = false; /// Holder for 1
    Text deux;
    deux.setFont(f1);
    deux.setString("2");
    deux.setCharacterSize(34);
    deux.setPosition(160, 497);

    Button Three(40, 40, 200, 500, c, C);
    bool three = false; /// Holder for 1
    Text trois;
    trois.setFont(f1);
    trois.setString("3");
    trois.setCharacterSize(34);
    trois.setPosition(210, 497);

    Button Four(40, 40, 100, 450, c, C);
    bool four = false; /// Holder for 1
    Text quatre;
    quatre.setFont(f1);
    quatre.setString("4");
    quatre.setCharacterSize(34);
    quatre.setPosition(110, 447);

    Button Five(40, 40, 150, 450, c, C);
    bool five = false; /// Holder for 1
    Text cinq;
    cinq.setFont(f1);
    cinq.setString("5");
    cinq.setCharacterSize(34);
    cinq.setPosition(160, 447);

    Button Six(40, 40, 200, 450, c, C);
    bool six = false; /// Holder for 1
    Text sice; /// I thougth french was special
    sice.setFont(f1);
    sice.setString("6");
    sice.setCharacterSize(34);
    sice.setPosition(210, 447);

    Button Seven(40, 40, 100, 400, c, C);
    bool seven = false; /// Holder for 1
    Text sept;
    sept.setFont(f1);
    sept.setString("7");
    sept.setCharacterSize(34);
    sept.setPosition(110, 397);

    Button Eight(40, 40, 150, 400, c, C);
    bool eight = false; /// Holder for 1
    Text huit;
    huit.setFont(f1);
    huit.setString("8");
    huit.setCharacterSize(34);
    huit.setPosition(160, 397);

    Button Nine(40, 40, 200, 400, c, C);
    bool nine = false; /// Holder for 1
    Text neuf;
    neuf.setFont(f1);
    neuf.setString("9");
    neuf.setCharacterSize(34);
    neuf.setPosition(210, 397);

    Button Zero(40, 40, 150, 550, c, C);
    bool zero = false;
    Text zro;
    zro.setFont(f1);
    zro.setString("O");
    zro.setCharacterSize(34);
    zro.setPosition(160, 547);

    Button Answer(80, 40, 300, 550, c, C);
    bool answer = false;
    Text reponse;
    reponse.setFont(f1);
    reponse.setString("Ans");
    reponse.setCharacterSize(34);
    reponse.setPosition(310, 547);


    /// |--------------------- Operations ---------------------|
    Button Decimal(40, 40, 200, 550, c, C);
    bool decimal = false;
    Text point;
    point.setFont(f1);
    point.setString(".");
    point.setCharacterSize(34);
    point.setPosition(210, 547);

    Button Equal(40, 40, 250, 550, c, C);
    bool equa = false;
    Text egal;
    egal.setFont(f1);
    egal.setString("=");
    egal.setCharacterSize(34);
    egal.setPosition(260, 548);

    Button Division(40, 40, 250, 350, c, C);
    bool division = false;
    Text desaccord;
    desaccord.setFont(f1);
    desaccord.setString("÷");
    desaccord.setCharacterSize(34);
    desaccord.setPosition(260, 348);

    Button Times(40, 40, 250, 400, c, C);
    bool times = false;
    Text temps;
    temps.setFont(f1);
    temps.setString(wstring(L"\u00D7"));
    temps.setCharacterSize(34);
    temps.setPosition(260, 398);

    Button Minus(40, 40, 250, 450, c, C);
    bool minu = false;
    Text moins;
    moins.setFont(f1);
    moins.setString(wstring(L"\u2212"));
    moins.setCharacterSize(34);
    moins.setPosition(260, 448);

    Button Add(40, 40, 250, 500, c, C);
    bool add = false;
    Text Plus;
    Plus.setFont(f1);
    Plus.setString("+");
    Plus.setCharacterSize(34);
    Plus.setPosition(260, 498);

    Button Backspace(140, 40, 100, 350, c, C);
    bool backspace = false;
    Text revoir;
    revoir.setFont(f1);
    revoir.setString("Delete");
    revoir.setCharacterSize(34);
    revoir.setPosition(110, 348);

    Button Cleer(80, 40, 300, 350, c, C);
    bool cleer = false;
    Text claire;
    claire.setFont(f1);
    claire.setString("Clr");
    claire.setCharacterSize(34);
    claire.setPosition(311, 348);

    Button Ln(80, 40, 300, 400, c, C);
    bool ln = false;
    Text nl;
    nl.setFont(f1);
    nl.setString("ln");
    nl.setCharacterSize(34);
    nl.setPosition(319, 398);

    Button Log(80, 40, 300, 450, c, C);
    bool log = false;
    Text gol;
    gol.setFont(f1);
    gol.setString("log");
    gol.setCharacterSize(34);
    gol.setPosition(308, 447);

    Button Logb(80, 40, 300, 500, c, C);
    bool logB = false;
    Text bgol;
    bgol.setFont(f1);
    bgol.setString("log");
    bgol.setCharacterSize(33);
    bgol.setPosition(303, 497);
    Text bgol2;
    bgol2.setFont(f1);
    bgol2.setString("b");
    bgol2.setCharacterSize(25);
    bgol2.setPosition(362, 513);

    Button Front(35, 40, 300, 600, c, C);
    bool fron = false;
    Text devant;
    devant.setFont(f1);
    devant.setString("(");
    devant.setCharacterSize(34);
    devant.setPosition(305, 594);

    Button Behind(35, 40, 345, 600, c, C);
    bool behind = false;
    Text derriere;
    derriere.setFont(f1);
    derriere.setString(")");
    derriere.setCharacterSize(34);
    derriere.setPosition(354, 594);


    /// |------------------- speceial things -----------------|
    Button Oil(40, 40, 150, 600, c, C); /// euler's number
    bool oil = false;
    Text huile;
    huile.setFont(f1);
    huile.setString("e");
    huile.setCharacterSize(34);
    huile.setPosition(160, 596);

    Button Pi(40, 40, 100, 600, c, C); /// self explanatory
    bool pi = false;
    Text tarte;
    tarte.setFont(f1);
    wstring L = L"\u03c0";
    tarte.setString(L);
    tarte.setCharacterSize(34);
    tarte.setPosition(110, 596);

    Button Me(40, 40, 100, 550, c, C);
    bool me = false;
    Text mois;
    mois.setFont(f1);
    mois.setString("i");
    mois.setCharacterSize(34);
    mois.setPosition(110, 548);

    Button See(40, 40, 200, 600, c, C); /// button to access constants (long term implementation)
    bool see = false;
    Text voir;
    voir.setFont(f1);
    voir.setString("c");
    voir.setCharacterSize(34);
    voir.setPosition(210, 596);

    /// |----------------- Calculator Window -------------------|
    RectangleShape w(Vector2f(600, 315));
    w.setPosition(105, 15);
    w.setFillColor(Bc);
    w.setOutlineColor(C);
    w.setOutlineThickness(5);

    /// |--------------------- Side bars ---------------------|
    vector <Vertex> p1;
    p1.push_back(Vertex(Vector2f(8, 10)));
    p1.push_back(Vertex(Vector2f(92, 10)));
    p1.push_back(Vertex(Vector2f(92, 692)));
    p1.push_back(Vertex(Vector2f(8, 692)));

    /// |-------------- Interface -------------|
    string s = ""; /// will hold equation
    vector <int> mbf; /// front bracket pointer
    vector <int> mbb; /// back bracket pointer

    /// |-------------- Clocks ------------|
    Clock grand;
    Time tick;
    float response = 125;
    int num1 = 0;
    int num2 = 0;
    int err = 0;
    Text equation;
    equation.setFont(f1);
    equation.setCharacterSize(34);
    equation.setPosition(150, 100);




    while (window.isOpen())     //the main game loop, exit if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Down))
                window.close();
        }   //ends the event loop

        window.clear(Bc); //clears the screen

        //cout << grand.getElapsedTime().asMilliseconds() << endl;

        if (!colour)
        {
            /// Mouse stuff
            x = Mouse::getPosition(window).x;
            y = Mouse::getPosition(window).y;
            if (Mouse::isButtonPressed(Mouse::Left))
                Click = true;
            else
                Click = false;

            /// |----------------- Check for mouse hover ----------------|
            /// numbers
            One.checkMouse(x, y, Click, one);
            if ((one) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "1" << endl;
                s = s + "1";
            }
            Two.checkMouse(x, y, Click, two);
            if ((two) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "2" << endl;
                s = s + "2";
            }
            Three.checkMouse(x, y, Click, three);
            if ((three) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "3" << endl;
                s = s + "3";
            }
            Four.checkMouse(x, y, Click, four);
            if ((four) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "4" << endl;
                s = s + "4";
            }
            Five.checkMouse(x, y, Click, five);
            if ((five) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "5" << endl;
                s = s + "5";
            }
            Six.checkMouse(x, y, Click, six);
            if ((six) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "6" << endl;
                s = s + "6";
            }
            Seven.checkMouse(x, y, Click, seven);
            if ((seven) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "7" << endl;
                s = s + "7";
            }
            Eight.checkMouse(x, y, Click, eight);
            if ((eight) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "8" << endl;
                s = s + "8";
            }
            Nine.checkMouse(x, y, Click, nine);
            if ((nine) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "9" << endl;
                s = s + "9";
            }
            Zero.checkMouse(x, y, Click, zero);
            if ((zero) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                cout << "O" << endl;
                s = s + "O";
            }
            Answer.checkMouse(x, y, Click, answer);
            if ((answer) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                //s = s + "2";
            }

            /// operations
            Decimal.checkMouse(x, y, Click, decimal);
            Equal.checkMouse(x, y, Click, equa);
            if ((equa) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                if ((num1 > 1) && (num2 > 1) && (num1 == num2))
                {
                    for (int i = 0; i < s.size(); i++)
                    {
                        if (s[i] == string("("))
                        {
                            int l = mbf.size();
                            mbf.push_back(0);
                            mbf.back() = l + 1 + err;
                        }
                        if (s[i] == string(")"))
                        {
                            mbb.push_back(mbf.back());
                            mbf.pop_back();
                            err++;
                        }
                    }
                    for (int i = 0; i < mbb.size(); i++)
                    {
                        int l = mbf.size();
                        mbf.push_back(0);
                        mbf.back() = l + 1;
                    }
                }
            }
            Division.checkMouse(x, y, Click, division);
            Times.checkMouse(x, y, Click, times);
            Minus.checkMouse(x, y, Click, minu);
            Add.checkMouse(x, y, Click, add);
            Backspace.checkMouse(x, y, Click, backspace);
            Cleer.checkMouse(x, y, Click, cleer);
            if ((cleer) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                s = "";
                num1 = 0;
                num2 = 0;
                for (int i = 0; i < mbf.size(); i++)
                {
                    mbf.pop_back();
                }
                for (int i = 0; i < mbb.size(); i++)
                {
                    mbb.pop_back();
                }
                err = 0;
            }
            Ln.checkMouse(x, y, Click, ln);
            Log.checkMouse(x, y, Click, log);
            Logb.checkMouse(x, y, Click, logB);
            Front.checkMouse(x, y, Click, fron);
            if ((fron) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                s = s + "(";
                num1++;
            }
            Behind.checkMouse(x, y, Click, behind);
            if ((behind) && (grand.getElapsedTime().asMilliseconds() > response))
            {
                grand.restart();
                s = s + ")";
                num2++;
            }
            for (int i = 0; i < mbf.size(); i++)
            {
                cout << mbf[i];

            }
            cout << " mbf" << endl;
            for (int i = 0; i < mbb.size(); i++)
            {
                cout << mbb[i];

            }
            cout << " mbb" << endl;

            /// special things
            Pi.checkMouse(x, y, Click, pi);
            Oil.checkMouse(x, y, Click, oil);
            Me.checkMouse(x, y, Click, me);
            See.checkMouse(x, y, Click, see);

            /// |--------------- Updating Colors --------------| this can be optimized by checking to see if the colour changed before updating for no reason
            /// |--- FILL ---|
            /// numbers
            One.setFillColor(c);
            Two.setFillColor(c);
            Three.setFillColor(c);
            Four.setFillColor(c);
            Five.setFillColor(c);
            Six.setFillColor(c);
            Seven.setFillColor(c);
            Eight.setFillColor(c);
            Nine.setFillColor(c);
            Zero.setFillColor(c);
            Answer.setFillColor(c);

            /// Operations
            Decimal.setFillColor(c);
            Equal.setFillColor(c);
            Division.setFillColor(c);
            Times.setFillColor(c);
            Minus.setFillColor(c);
            Add.setFillColor(c);
            Backspace.setFillColor(c);
            Cleer.setFillColor(c);
            Ln.setFillColor(c);
            Log.setFillColor(c);
            Logb.setFillColor(c);
            Front.setFillColor(c);
            Behind.setFillColor(c);

            /// special things
            Pi.setFillColor(c);
            Oil.setFillColor(c);
            Me.setFillColor(c);
            See.setFillColor(c);

            /// |--- OUTLINE ---|
            /// numbers
            One.setOutlineColor(C);
            Two.setOutlineColor(C);
            Three.setOutlineColor(C);
            Four.setOutlineColor(C);
            Five.setOutlineColor(C);
            Six.setOutlineColor(C);
            Seven.setOutlineColor(C);
            Eight.setOutlineColor(C);
            Nine.setOutlineColor(C);
            Zero.setOutlineColor(C);
            Answer.setOutlineColor(C);

            /// Operations
            Decimal.setOutlineColor(C);
            Equal.setOutlineColor(C);
            Division.setOutlineColor(C);
            Times.setOutlineColor(C);
            Minus.setOutlineColor(C);
            Add.setOutlineColor(C);
            Backspace.setOutlineColor(C);
            Cleer.setOutlineColor(C);
            Ln.setOutlineColor(C);
            Log.setOutlineColor(C);
            Logb.setOutlineColor(C);
            Front.setOutlineColor(C);
            Behind.setOutlineColor(C);

            /// special things
            Pi.setOutlineColor(C);
            Oil.setOutlineColor(C);
            Me.setOutlineColor(C);
            See.setOutlineColor(C);

            ///|--- TEXT ---|
            /// Numbers
            un.setColor(Cc);
            deux.setColor(Cc);
            trois.setColor(Cc);
            quatre.setColor(Cc);
            cinq.setColor(Cc);
            sice.setColor(Cc);
            sept.setColor(Cc);
            huit.setColor(Cc);
            neuf.setColor(Cc);
            zro.setColor(Cc);
            reponse.setColor(Cc);

            /// operations
            point.setColor(Cc);
            egal.setColor(Cc);
            desaccord.setColor(Cc);
            temps.setColor(Cc);
            moins.setColor(Cc);
            Plus.setColor(Cc);
            revoir.setColor(Cc);
            claire.setColor(Cc);
            nl.setColor(Cc);
            gol.setColor(Cc);
            bgol.setColor(Cc);
            bgol2.setColor(Cc);
            devant.setColor(Cc);
            derriere.setColor(Cc);

            /// special things
            tarte.setColor(Cc);
            huile.setColor(Cc);
            mois.setColor(Cc);
            voir.setColor(Cc);


            /// |-------------------- Colours/Settings -------------------|  more window-related buttons to be added later
            /// Mouse stuff (needs to be more than once to account for state change)
            x = Mouse::getPosition(window).x;
            y = Mouse::getPosition(window).y;
            if (Mouse::isButtonPressed(Mouse::Left))
                Click = true;
            else
                Click = false;

            Colour.checkMouse(x, y, Click, colour); /// Will take to next screen
            if (colour)
                bak = false;

            Colour.setFillColor(c);
            Colour.setOutlineColor(C);
            couleur.setColor(Cc);

            Settings.checkMouse(x, y, Click, settings);
            Settings.setFillColor(c);
            Settings.setOutlineColor(C);
            reglages.setColor(Cc);

            /// window color updates
            w.setFillColor(c);
            w.setOutlineColor(C);

            /// side bar updates
            p1[0].color = c;
            p1[1].color = C;
            p1[2].color = Cc;
            p1[3].color = Bc;

            /// equation update
            equation.setString(s);
            equation.setColor(Cc);

            ///|----------------------------- DRAWING -------------------------------|
            /// window
            window.draw(w);
            window.draw(&p1[0], p1.size(), Quads);

            /// numbers
            window.draw(One);
            window.draw(Two);
            window.draw(Three);
            window.draw(Four);
            window.draw(Five);
            window.draw(Six);
            window.draw(Seven);
            window.draw(Eight);
            window.draw(Nine);
            window.draw(Zero);
            window.draw(Answer);

            /// operations
            window.draw(Decimal);
            window.draw(Equal);
            window.draw(Division);
            window.draw(Times);
            window.draw(Minus);
            window.draw(Add);
            window.draw(Backspace);
            window.draw(Cleer);
            window.draw(Ln);
            window.draw(Log);
            window.draw(Logb);
            window.draw(Front);
            window.draw(Behind);

            /// special stuff
            window.draw(Pi);
            window.draw(Oil);
            window.draw(Me);
            window.draw(See);

            /// buttons for other windows
            window.draw(Colour);
            window.draw(Settings);

            /// numbers
            window.draw(un);
            window.draw(deux);
            window.draw(trois);
            window.draw(quatre);
            window.draw(cinq);
            window.draw(sice);
            window.draw(sept);
            window.draw(huit);
            window.draw(neuf);
            window.draw(zro);
            window.draw(reponse);

            /// operations
            window.draw(point);
            window.draw(egal);
            window.draw(desaccord);
            window.draw(temps);
            window.draw(moins);
            window.draw(Plus);
            window.draw(revoir);
            window.draw(claire);
            window.draw(nl);
            window.draw(gol);
            window.draw(bgol);
            window.draw(bgol2);
            window.draw(devant);
            window.draw(derriere);

            /// special stuff
            window.draw(tarte);
            window.draw(huile);
            window.draw(mois);
            window.draw(voir);

            /// other windows
            window.draw(couleur);
            window.draw(reglages);

            /// equation
            window.draw(equation);
        }
        else
        {
            /// Mouse stuff (needs to be more than once to account for state change)
            x = Mouse::getPosition(window).x;
            y = Mouse::getPosition(window).y;
            if (Mouse::isButtonPressed(Mouse::Left))
                Click = true;
            else
                Click = false;

            /// First button
            R1.checkMouse(x, y, Click, r1); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (r1)) || (holder1)))
            {
                if (!holder1)
                    x0 = x - R1.getPosition().x;
                holder1 = true;
                if ((R1.getPosition().x > (450 - 256/2)) && (R1.getPosition().x < (450 + 256/2)))
                    R1.setX(x - x0);
                if ((R1.getPosition().x < (450 - 256/2)))
                    R1.setX(450 - 256/2 + 1);
                if ((R1.getPosition().x > (450 + 256/2)))
                    R1.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holder1 = false;
            }
            R2.checkMouse(x, y, Click, r2); /// works now
            if ((!holder1) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (r2)) || (holder2)))
            {
                if (!holder2)
                    x0 = x - R2.getPosition().x;
                holder2 = true;
                if ((R2.getPosition().x > (450 - 256/2)) && (R2.getPosition().x < (450 + 256/2)))
                    R2.setX(x - x0);
                if ((R2.getPosition().x < (450 - 256/2)))
                    R2.setX(450 - 256/2 + 1);
                if ((R2.getPosition().x > (450 + 256/2)))
                    R2.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holder2 = false;
            }
            R3.checkMouse(x, y, Click, r3); /// works now
            if ((!holder2) && (!holder1) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (r3)) || (holder3)))
            {
                if (!holder3)
                    x0 = x - R3.getPosition().x;
                holder3 = true;
                if ((R3.getPosition().x > (450 - 256/2)) && (R3.getPosition().x < (450 + 256/2)))
                    R3.setX(x - x0);
                if ((R3.getPosition().x < (450 - 256/2)))
                    R3.setX(450 - 256/2 + 1);
                if ((R3.getPosition().x > (450 + 256/2)))
                    R3.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holder3 = false;
            }
            R4.checkMouse(x, y, Click, r4); /// works now
            if ((!holder2) && (!holder1) && (!holder3) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (r4)) || (holder4)))
            {
                if (!holder4)
                    x0 = x - R4.getPosition().x;
                holder4 = true;
                if ((R4.getPosition().x > (450 - 256/2)) && (R4.getPosition().x < (450 + 256/2)))
                    R4.setX(x - x0);
                if ((R4.getPosition().x < (450 - 256/2)))
                    R4.setX(450 - 256/2 + 1);
                if ((R4.getPosition().x > (450 + 256/2)))
                    R4.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holder4 = false;
            }
            G1.checkMouse(x, y, Click, g1); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holder1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (g1)) || (holdeg1)))
            {
                if (!holdeg1)
                    x0 = x - G1.getPosition().x;
                holdeg1 = true;
                if ((G1.getPosition().x > (450 - 256/2)) && (G1.getPosition().x < (450 + 256/2)))
                    G1.setX(x - x0);
                if ((G1.getPosition().x < (450 - 256/2)))
                    G1.setX(450 - 256/2 + 1);
                if ((G1.getPosition().x > (450 + 256/2)))
                    G1.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeg1 = false;
            }
            G2.checkMouse(x, y, Click, g2); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holder1) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (g2)) || (holdeg2)))
            {
                if (!holdeg2)
                    x0 = x - G2.getPosition().x;
                holdeg2 = true;
                if ((G2.getPosition().x > (450 - 256/2)) && (G2.getPosition().x < (450 + 256/2)))
                    G2.setX(x - x0);
                if ((G2.getPosition().x < (450 - 256/2)))
                    G2.setX(450 - 256/2 + 1);
                if ((G2.getPosition().x > (450 + 256/2)))
                    G2.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeg2 = false;
            }
            G3.checkMouse(x, y, Click, g3); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holder1) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (g3)) || (holdeg3)))
            {
                if (!holdeg3)
                    x0 = x - G3.getPosition().x;
                holdeg3 = true;
                if ((G3.getPosition().x > (450 - 256/2)) && (G3.getPosition().x < (450 + 256/2)))
                    G3.setX(x - x0);
                if ((G3.getPosition().x < (450 - 256/2)))
                    G3.setX(450 - 256/2 + 1);
                if ((G3.getPosition().x > (450 + 256/2)))
                    G3.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeg3 = false;
            }
            G4.checkMouse(x, y, Click, g4); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg3) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holder1) && (!holdeb1) && (!holdeb2) && (!holdeb3) && (((Click) && (g4)) || (holdeg4)))
            {
                if (!holdeg4)
                    x0 = x - G4.getPosition().x;
                holdeg4 = true;
                if ((G4.getPosition().x > (450 - 256/2)) && (G4.getPosition().x < (450 + 256/2)))
                    G4.setX(x - x0);
                if ((G4.getPosition().x < (450 - 256/2)))
                    G4.setX(450 - 256/2 + 1);
                if ((G4.getPosition().x > (450 + 256/2)))
                    G4.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeg4 = false;
            }
            B1.checkMouse(x, y, Click, b1); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holder1) && (!holdeb2) && (!holdeb3) && (((Click) && (b1)) || (holdeb1)))
            {
                if (!holdeb1)
                    x0 = x - B1.getPosition().x;
                holdeb1 = true;
                if ((B1.getPosition().x > (450 - 256/2)) && (B1.getPosition().x < (450 + 256/2)))
                    B1.setX(x - x0);
                if ((B1.getPosition().x < (450 - 256/2)))
                    B1.setX(450 - 256/2 + 1);
                if ((B1.getPosition().x > (450 + 256/2)))
                    B1.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeb1 = false;
            }
            B2.checkMouse(x, y, Click, b2); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holder1) && (!holdeb3) && (((Click) && (b2)) || (holdeb2)))
            {
                if (!holdeb2)
                    x0 = x - B2.getPosition().x;
                holdeb2 = true;
                if ((B2.getPosition().x > (450 - 256/2)) && (B2.getPosition().x < (450 + 256/2)))
                    B2.setX(x - x0);
                if ((B2.getPosition().x < (450 - 256/2)))
                    B2.setX(450 - 256/2 + 1);
                if ((B2.getPosition().x > (450 + 256/2)))
                    B2.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeb2 = false;
            }
            B3.checkMouse(x, y, Click, b3); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb4) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holder1) && (((Click) && (b3)) || (holdeb3)))
            {
                if (!holdeb3)
                    x0 = x - B3.getPosition().x;
                holdeb3 = true;
                if ((B3.getPosition().x > (450 - 256/2)) && (B3.getPosition().x < (450 + 256/2)))
                    B3.setX(x - x0);
                if ((B3.getPosition().x < (450 - 256/2)))
                    B3.setX(450 - 256/2 + 1);
                if ((B3.getPosition().x > (450 + 256/2)))
                    B3.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeb3 = false;
            }
            B4.checkMouse(x, y, Click, b4); /// works now
            if ((!holder2) && (!holder3) && (!holder4) && (!holdeg4) && (!holdeb3) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holder1) && (((Click) && (b4)) || (holdeb4)))
            {
                if (!holdeb4)
                    x0 = x - B4.getPosition().x;
                holdeb4 = true;
                if ((B4.getPosition().x > (450 - 256/2)) && (B4.getPosition().x < (450 + 256/2)))
                    B4.setX(x - x0);
                if ((B4.getPosition().x < (450 - 256/2)))
                    B4.setX(450 - 256/2 + 1);
                if ((B4.getPosition().x > (450 + 256/2)))
                    B4.setX(450 + 256/2 - 1);
            }
            if ((!r1) && (!r2) && (!r3) && (!r4) && (!g1) && (!g2) && (!g3) && (!g4) && (!b1) && (!b2) && (!b3) && (!b4) && (!Click))
            {
                holdeb4 = false;
            }

            C = Color(R1.getPosition().x - 450 + 256/2, G1.getPosition().x - 450 + 256/2, B1.getPosition().x - 450 + 256/2); /// outline
            c = Color(R2.getPosition().x - 450 + 256/2, G2.getPosition().x - 450 + 256/2, B2.getPosition().x - 450 + 256/2); /// fill
            Cc = Color(R3.getPosition().x - 450 + 256/2, G3.getPosition().x - 450 + 256/2, B3.getPosition().x - 450 + 256/2); /// text
            Bc = Color(R4.getPosition().x - 450 + 256/2, G4.getPosition().x - 450 + 256/2, B4.getPosition().x - 450 + 256/2); /// background

            R1.setFillColor(c);
            R2.setFillColor(c);
            R3.setFillColor(c);
            R4.setFillColor(c);
            G1.setFillColor(c);
            G2.setFillColor(c);
            G3.setFillColor(c);
            G4.setFillColor(c);
            B1.setFillColor(c);
            B2.setFillColor(c);
            B3.setFillColor(c);
            B4.setFillColor(c);
            Back.setFillColor(c);

            R1.setOutlineColor(C);
            R2.setOutlineColor(C);
            R3.setOutlineColor(C);
            R4.setOutlineColor(C);
            G1.setOutlineColor(C);
            G2.setOutlineColor(C);
            G3.setOutlineColor(C);
            G4.setOutlineColor(C);
            B1.setOutlineColor(C);
            B2.setOutlineColor(C);
            B3.setOutlineColor(C);
            B4.setOutlineColor(C);



            retourner.setColor(Cc);
            Outline.setColor(Cc);
            Fill.setColor(Cc);
            t.setColor(Cc);
            Background.setColor(Cc);






            Back.checkMouse(x, y, Click, bak);
            if ((bak) && (!holder1) && (!holder2) && (!holder3) && (!holdeg1) && (!holdeg2) && (!holdeg3) && (!holdeb1) && (!holdeb2) && (!holdeb3))
                colour = false;

            Back.setOutlineColor(C);

            window.draw(R1);
            window.draw(R2);
            window.draw(R3);
            window.draw(R4);
            window.draw(G1);
            window.draw(G2);
            window.draw(G3);
            window.draw(G4);
            window.draw(B1);
            window.draw(B2);
            window.draw(B3);
            window.draw(B4);

            window.draw(Back);
            window.draw(Outline);
            window.draw(Fill);
            window.draw(t);
            window.draw(Background);
            window.draw(retourner);

        }



        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}

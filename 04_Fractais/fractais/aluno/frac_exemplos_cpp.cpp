#include <lib/pen.h>

void triangulo(Pen &p, int lado){
    if(lado < 10)
        return;
    for(int i = 0; i < 3; i++){
        p.walk(lado);
        p.left(120);
         p.setColor( rand() %455, rand() % 45, rand() % 55);
        triangulo(p, lado/2);
    }
}

void embuarvore(Pen& p, int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= (p.rand() % 7 - 3);
    if(lado < 10)
        return;
    p.setColor( rand() %455, rand() % 45, rand() % 55);
    p.walk(lado);
    p.right(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.right(ang);
    //p.setColor(sf::Color::Green);
    p.walk(-lado);
}


void trigo(Pen& p, int lado){
    if(lado < 0.1)
        return;
    for(int i = 0; i < 7; i++){
        p.walk(lado);
        p.right(45);
        p.setColor(455, 445, 555);
        trigo(p, lado / 5);
        p.left(90);
        trigo(p, lado / 5);
        p.right(45);
    }
    p.walk(-lado * 7);
}

void floco(Pen& p, int lado){
    if(lado < 3)
        return;
    p.setColor(95, 135, 135 );
    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco(p,lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco(p,lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco(p,lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco(p,lado / 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco(p,lado / 3);
}

void fractal(){
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 500);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);

    //embuarvore(p, 100);
    //triangulo(p, 400);
    //trigo(p, 90);
    floco(p, 100);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}

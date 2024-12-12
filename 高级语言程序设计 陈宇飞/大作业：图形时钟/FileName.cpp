#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cmath>
#include <graphics.h>
#include <conio.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
double pi = std::acos(-1);

// ����һ��ʱ����
class Clock {
public:
    void init();  // ��ʼ��ͼ�ν���
    void drawClockFace();  // �����ӱ�����
    void drawHands(int hour, int minute, int second);  // ����ʱ�롢���롢����
    void click(int x0, int y0, int size, COLORREF C);//�����������Ч
    void startup(); //��ʼ����������
    void paintstar();//��������
    void moon();  //��������
    void meteor();  //��������
    COLORREF mix_color(COLORREF bg, COLORREF color, double alpha); // �����ɫ����
    void SDF_circle(POINT p, COLORREF color, int r); // �����:����SDFԲ��
    void SDF_solidcircle(POINT p, COLORREF color, int r); // �����:����SDFʵ��Բ��
    void updateTime();  // �������л���
    struct STAR
    {
        int x;
        int y;
    };
    STAR star[100];
}; 

//��ʼ��ͼ�ν���
void Clock::init()
{
    initgraph(640, 720);
    // ��ʼ����
    for (int i = 0; i < 500; i += 30)
    {
        SDF_solidcircle({ 320,360 }, RGB(23, 21, 59), i); // ���ƿ����ʵ��Բ
    }
    setbkcolor(RGB(23, 21, 59)); 
    BeginBatchDraw();  // ����˫�����ͼ
    cleardevice(); 
}
// ����ʱ������
void Clock::drawClockFace() 
{
    SDF_circle({ 320, 360 }, RGB(200, 172, 214), 220);  // ʹ��SDF + Alpha Blending ��������
    for (int i = 0; i < 12; ++i) 
    {
        double angle = (i + 1) * 30 * pi / 180;  // ÿ��Сʱ�ĽǶ�
        int x = 320 + 200 * sin(angle);  // �������ֵ�����
        int y = 360 - 200 * cos(angle);
        
        if (i == 11 || i == 2 || i == 5 || i == 8)
            SDF_solidcircle({ x,y }, RGB(221, 128, 128), 6);
        else
            SDF_circle({ x,y }, RGB(142, 124, 195), 2);

        settextstyle(20, 0, _T("����"));
        setcolor(RGB(209, 220, 243));
        outtextxy(130, 650, _T("��ҹ�����Һ�ɫ���۾�����ȴ����Ѱ�ҹ�����"));
        outtextxy(500, 680, _T("�����˳�"));
    }
}
// ����ʱ�롢���롢����
void Clock::drawHands(int hour, int minute, int second) {
    // ����ʱ�롢���롢����ĽǶ�
    double hourAngle = (hour % 12 + minute / 60.0) * 30; 
    double minuteAngle = minute * 6;  
    double secondAngle = second * 6; 
    // �������룺��ʵ��Բ�Ĵ�С��ʾ����
    SDF_solidcircle({ 320, 360 }, RGB(209, 194, 243), second / 60.0 * 220);
    
    // ����ʱ��
    for (int i = 0; i < 10; ++i)
    {
        SDF_solidcircle({ int(320 + i * 12 * sin(pi / 180 * hourAngle)), int(360 - i * 12 * cos(pi / 180 * hourAngle)) }, RGB(99, 64, 152), 2);
    }
    // ���Ʒ���
    for (int i = 0; i < 15; ++i)
    {
        SDF_solidcircle({ int(320+i * 10 * sin(pi / 180 * minuteAngle)), int(360 - i * 10 * cos(pi / 180 * minuteAngle)) }, RGB(142, 124, 195), 1);
    }

}
//�����������Ч
void Clock::click(int x0, int y0, int size, COLORREF C)
{
    double  m, n;
    double x = 0;
    double y = 0;
    double i;
    int tempx = x;
    int tempy = y;
    for (i = 0; i <= 2 * size; i = i + 0.01)
    {
        //�����������
        m = i;
        n = -size * (((sin(i) * sqrt(fabs(cos(i)))) / (sin(i) + 1.4142)) - 2 * sin(i) + 2);
        //ת��Ϊ�ѿ�������
        x = n * cos(m) + x0;
        y = n * sin(m) + y0;
        putpixel(x , y , C);
        putpixel(x + 1, y + 1, C);
    }
}
//��ʼ����������
void Clock::startup()
{
    for (int i = 0; i < 50; i++)
    {
        star[i].x = rand() % 640;
        star[i].y = rand() % 720;
    }
}
//��������
void Clock::paintstar()
{
    for (int i = 0; i < 50; i++)
    {
        putpixel(star[i].x, star[i].y, WHITE);
    }

}
//��������
void Clock::moon()
{
    setcolor(WHITE);
    setfillcolor(WHITE);
    SDF_solidcircle({ 120, 80 }, WHITE, 50);
    SDF_solidcircle({ 150,60 }, RGB(23, 21, 59), 50);

}
//��������
void Clock::meteor()
{
    int a1 = rand() % 640;
    int b1 = rand() % 720;
    for (int i = 0; i < 40; i++)
    {

        setcolor(WHITE);
        setlinestyle(PS_SOLID, 1);
        circle(a1, b1, 1);
        a1 = a1 - 2;
        b1 = b1 + 1;
    }

}
// �����ɫ����
COLORREF  Clock::mix_color(COLORREF bg, COLORREF color, double alpha) {
    COLORREF result;
    result = RGB(GetRValue(bg) * (1 - alpha) + GetRValue(color) * alpha,
        GetGValue(bg) * (1 - alpha) + GetGValue(color) * alpha,
        GetBValue(bg) * (1 - alpha) + GetBValue(color) * alpha);
    return result;
}
// �����:����SDFԲ��
void  Clock::SDF_circle(POINT p, COLORREF color, int r) {
    for (int i = p.x - r - 10; i < p.x + r + 10; i++) {
        for (int j = p.y - r - 10; j < p.y + r + 10; j++) {
            POINT p1 = { i, j };
            double d = sqrt(pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2)) - r;  // �������
            double alpha = 1 - abs(d) / 4;  // ����͸����

            if (alpha >= 0 && alpha <= 1) {
                COLORREF bg = getpixel(i, j);  // ��ȡ������ɫ
                COLORREF result = mix_color(bg, color, alpha);  // ������ɫ���
                putpixel(i, j, result);  // ��������
            }
        }
    }
}
// �����:����SDFʵ��Բ��
void  Clock::SDF_solidcircle(POINT p, COLORREF color, int r) {
    for (int i = p.x - r - 10; i < p.x + r + 10; i++) {
        for (int j = p.y - r - 10; j < p.y + r + 10; j++) {
            POINT p1 = { i, j };
            double d = sqrt(pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2)) - r;  // �������
            double alpha = 1 - abs(d) / 3;  // ����͸����

            if (d < 0)
            {
                putpixel(i, j, color);
                continue;
            }
            if (alpha >= 0 && alpha <= 1) {
                COLORREF bg = getpixel(i, j);  // ��ȡ������ɫ
                COLORREF result = mix_color(bg, color, alpha);  // ������ɫ���
                putpixel(i, j, result);  // ��������
            }
        }
    }
}
// �������л���
void Clock::updateTime() {
    ExMessage msg;
    int count = 0;
    bool timedisplay = true;
    while (true)
    {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;
        if (count > 100)
            count = 0;
        while (peekmessage(&msg, EX_MOUSE)) // ��������ȡ�����Ϣ
        {
            if (msg.message == WM_LBUTTONDOWN) // ���˳�����������¼�
            {
                int x = msg.x;
                int y = msg.y;
                click(x, y,10, RGB(221, 128, 128));
                FlushBatchDraw();
                timedisplay = !timedisplay;
            }
        }
        cleardevice();  // �����Ļ
        drawHands(hour, minute, second);  // ����ָ��
        drawClockFace();  // ���»�������
        if (timedisplay)
        {
            TCHAR num_hour[10];
            if (hour < 10)
                _stprintf_s(num_hour, _T("%02d"), hour);
            else
                _stprintf_s(num_hour, _T("%d"), hour);
            TCHAR num_minute[10];
            if (minute < 10)
                _stprintf_s(num_minute, _T("%02d"), minute);  
            else// �������Сʱ
                _stprintf_s(num_minute, _T("%d"), minute);
            TCHAR middle[10];
            _stprintf_s(middle, _T("%s"), _T(":"));
            setcolor(RGB(209, 220, 243));
            settextstyle(50, 0, _T("����")); 
            outtextxy(255, 50, num_hour);
            outtextxy(310, 50, middle);
            outtextxy(338, 50, num_minute);
        }
        moon(); 
        paintstar();
        if (count % 60 == 0)
            meteor();
        if (count % 30 == 0)
            meteor();
        count++;
        FlushBatchDraw();  // ˢ����Ļ��ʾ
    }
    EndBatchDraw();  // ����˫�����ͼ
}

int main() {
    
    Clock clock;

    //����BGM
    mciSendString("open river_flows_in_you.mp3 alias bgm", 0, 0, 0);
    mciSendString("play bgm repeat", 0, 0, 0);
    //��ʼ������
    clock.init();
    //��ʼ����������
    clock.startup();
    //����ʱ������л���
    clock.updateTime();

    mciSendString("close music", nullptr, 0, nullptr);
    closegraph();

    return 0;
}

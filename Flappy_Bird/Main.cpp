#include "dinhnghia.h"
#include "Picture.h"
#include "Bird.h"
#include "OngKhoi.h"
void Play(RenderWindow &app);
void GameOver(RenderWindow &app);
void StartGame(RenderWindow &app);
string Convert(int a);
int getBestScore();
void UpdateHighScore();
int Score;
string Convert(int a){
	if (a == 0) return "0";
	string ans = "";
	while (a > 0){
		int r = a % 10;
		ans = char(r + 48) + ans;
		a /= 10;
	}
	return ans;
}
void StartGame(RenderWindow &app){
	/// Background
	Picture background("image/background.png", 0, 0, 1000, 500);
//	background.setColor(Color::Red);
	Picture tab("image/tab.png", 150, 175, 100, 75);
	Bird bird(100, 200);
	bird.setRotation(-1);
	/// dung de map di chuyen
	int cnt = 0;
	while (app.isOpen()){
		Event e;
		app.pollEvent(e);
		if (e.type == Event::Closed) app.close();

		app.clear(Color::White);


		/// back ground
		cnt -= 2;
		if (cnt <-333) cnt = cnt + 333;
		background.setPosition(cnt, 0);
		background.display(app);

		/// in ra hinh tab
		tab.display(app);
		
		/// chim
		bird.display(app);

		/// neu co su kien click chuyen sang choi
		if (Mouse::isButtonPressed(Mouse::Left)) return;

		app.display();  //window hien len may tính
	}
}
void Play(RenderWindow &app){
	/// diem 
	Score = 0;
	int sum = 3;
	/// font chu va cac kieu cua diem
	Font font;
	font.loadFromFile("font/flappy.ttf");//lay font
	Text TextScore;  //chu
	TextScore.setFont(font);
	TextScore.setPosition(300, 20);
	TextScore.setStyle(Text::Bold);  //in dam
	TextScore.setCharacterSize(30);

	/// bat dau choi
	Picture background("image/background.png", 0, 0, 1000, 500);
	Bird bird(100,200);
	
	/// danh sach cac ong khoi
	vector<OngKhoi> dsOngKhoi;
	dsOngKhoi.clear();

	/// dong ho de do phim cu 500 ms dc bam 1 lan
	Clock dongho;
	dongho.restart();
	
	/// dung de dem them cac ong khoi moi
	int dem = 0;

	/// dung de cho hinh nen di chuyen
	int cnt = 0;

	/// bien nay ho tro de tao them ong khoi
	OngKhoi temp_ongkhoi;
	
	/// bat dau : vi tri ong khoi van con trong man hinh
	int batdau = 0;

	while (app.isOpen()){
		
		Event e;//bat su kien tat game
		app.pollEvent(e);
		if (e.type == Event::Closed) app.close();

		app.clear(Color::White);

		/// di chuyen hinh nen va in ra hinh nen
		cnt -= 2;
		if (cnt <-333) cnt = cnt + 333;
		background.setPosition(cnt, 0);
		background.display(app);
		/// in ra con chim
		bird.display(app);

		/// xu ly su kien bam chuot
		if (Mouse::isButtonPressed(Mouse::Left)){
			Time thoigian;
			thoigian = dongho.getElapsedTime();  //lay thoi gian
			if (thoigian.asMilliseconds() >= 15)
			{//  sau 15ms
				bird.setRotation(1);
				dongho.restart();
			}
		}
		/// cho chim di chuyen
		bird.move();
		/// in ra danh sach cac ong khoi
		if (!dsOngKhoi.empty()){
			foru(i, batdau, dsOngKhoi.size() - 1) dsOngKhoi[i].display(app);
			foru(i, batdau, dsOngKhoi.size() - 1){
				dsOngKhoi[i].move();
				if (dsOngKhoi[i].getX() < -32) batdau = i + 1;
			}
		}
		/// in ra diem
		TextScore.setString(Convert(Score));
		app.draw(TextScore);
		/// them vao cac ong khoi moi
		if (dem == 0){
			dem = -80;
			int dd = rand() % 210 + 20;
			// tu tren xuong
			temp_ongkhoi.setOngKhoi(685, dd, 1);
			dsOngKhoi.push_back(temp_ongkhoi);
			/// tu duoi len
			dd = 230- dd;
			temp_ongkhoi.setOngKhoi(685, dd, 0);
			dsOngKhoi.push_back(temp_ongkhoi);
		}
		dem++;
		/// kiem tra game over
		bool gameover = false;
		if (!dsOngKhoi.empty()){
			Vector2i vitri = bird.getPosition();//toa do cua con chim
			Vector2i Kichthuoc = bird.getSize();//kich thuoc cua chim
			if (vitri.y == 400) gameover = true;
			foru(i, batdau, dsOngKhoi.size() - 1)
			if (dsOngKhoi[i].vacham(vitri.x, vitri.y, Kichthuoc.x, Kichthuoc.y))
				gameover = true;
		}
		if (gameover){
			UpdateHighScore();
			return;
		}
		/// kiem tra su kien tang diem
		if (!dsOngKhoi.empty() && Score<dsOngKhoi.size()){
			int xx = dsOngKhoi[Score].getX();
			int xc = bird.getPosition().x;
			if (xx < xc) Score += 1;
		}
		app.display();
	}
}

int getBestScore(){
	int ans;
	FILE *f;
	f = fopen("highscore.txt", "r");
	fscanf(f, "%d", &ans);
	fclose(f);
	return ans;
}

void UpdateHighScore(){
	int z = getBestScore();
	if (Score <= z) return;
	FILE *f;
	f = fopen("highscore.txt", "w");
	fprintf(f, "%d", Score);
	fclose(f);
}

void GameOver(RenderWindow &app){
	Font font;
	font.loadFromFile("font/flappy.ttf");
	/// background
	Picture background("image/background.png", 0, 0, 1000, 500);
	/// text gameover
	Text TextGameOver;
	TextGameOver.setFont(font);
	TextGameOver.setPosition(200, 50);
	TextGameOver.setCharacterSize(50);
	TextGameOver.setStyle(Text::Bold);
	TextGameOver.setString("GAME OVER");
	/// text Score
	Text TextScore;
	TextScore.setFont(font);
	TextScore.setPosition(250, 120);
	TextScore.setCharacterSize(30);
	TextScore.setString("SCORE : "+Convert(Score/2));
	TextScore.setFillColor(Color::Red);
	/// text Best Score
	Text TextBestScore;
	TextBestScore.setFont(font);
	TextBestScore.setPosition(250, 170);
	TextBestScore.setCharacterSize(30);
	TextBestScore.setString("BEST : " + Convert(getBestScore()/2));
	TextBestScore.setFillColor(Color::Red);
	/// text Press any key to restart
	Text TextPre;
	TextPre.setFont(font);
	TextPre.setPosition(160, 250);
	TextPre.setCharacterSize(30);
	TextPre.setString("Press Enter to restart\n Press Escape to exit");
	TextPre.setFillColor(Color::Blue);

	while (app.isOpen()){
		app.clear(Color::White);
		Event e;
		app.pollEvent(e);
		if (e.type == Event::Closed) app.close();

		background.display(app);
		app.draw(TextGameOver);
		app.draw(TextScore);
		app.draw(TextPre);
		app.draw(TextBestScore);

		/// xu ly su kien bam phim bat ki de restart
		if (Keyboard::isKeyPressed(Keyboard::Return)) return;
		if (Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);
		app.display();
	}
}
int main(){
	FreeConsole();
	RenderWindow app(VideoMode(666, 480), "Flappy Bird");
	app.setFramerateLimit(70);

	/// lenh nay de sinh so ngau nhien cho chinh xac
	srand(time(NULL));
	while (app.isOpen()){
		app.clear(Color::White);
		StartGame(app);
		Play(app);
		//sleep(milliseconds(500));
		GameOver(app);
	}
	return 0;
}
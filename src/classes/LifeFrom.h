class LifeForm {
	private:
		bool alive;
	public:
		int  posx;
		int  posy;
		const char *avatar;

		LifeForm();
		LifeForm(int x, int y, const char *avatar);
		void set_pos(int x, int y);
		void set_avatar(const char *avatar);
		void kill();
		void birth();
		bool is_alive();
};

/// class Cursor - 
class Cursor {
  // Operations
public:
  Cursor (int x = 0, int y = 0, std::vector MapCell);
  bool isMapCell ();
  void move (Position& destination);
};


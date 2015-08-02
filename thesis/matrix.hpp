#ifndef MATRIX_HPP
#define MATRIX_HPP

class matrix
{
public:
	matrix(unsigned n, unsigned m);
	virtual ~matrix();

public:
	unsigned get_width() const;
	unsigned get_hight() const;

public:
	void print();
	void clear();

private:
	void init();

protected:
	virtual void fill_matrix(int begin = 0, int end = 0) = 0;

protected:
	void set_value(unsigned i, unsigned j, int v);

private:
	int** m_matrix;
	unsigned m_width;
	unsigned m_hight;	

private:
	matrix(const matrix&);
	matrix& operator=(const matrix&);
};

#endif // MATRIX_HPP

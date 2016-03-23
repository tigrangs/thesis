#ifndef RUNDOM_NUMBER_GENERATOR_HPP
#define RUNDOM_NUMBER_GENERATOR_HPP

class rundom_number_generator
{
    typedef rundom_number_generator RND;
public:
    static RND* get_instance();

public:
    /// Return rundom number in range [begin, end]
    int get_number(int begin, int end);

private:
    rundom_number_generator();
    rundom_number_generator(const rundom_number_generator&);
    rundom_number_generator& operator=(const rundom_number_generator&);
};

#endif // RUNDOM_NUMBER_GENERATOR_HPP

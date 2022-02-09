#include <iostream>
#include <string>
#include <vector>

class Product1
{
public:
    std::vector<std::string> parts_;
    void ListParts() const
    {
        std::cout << "Product parts: ";
        for (size_t i = 0; i < parts_.size(); i++)
        {
            if (parts_[i] == parts_.back())
                std::cout << parts_[i];
            else
                std::cout << parts_[i] << ", ";
        }
        std::cout << "\n\n";
    }
};

class Builder
{
public:
    virtual ~Builder() {}
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product1 *product;

public:
    ConcreteBuilder1() { this->Reset(); }
    ~ConcreteBuilder1() { delete product; }

    void Reset() { this->product = new Product1(); }

    void ProducePartA() const override
    {
        this->product->parts_.push_back("PartA1");
    }
    void ProducePartB() const override
    {
        this->product->parts_.push_back("PartB1");
    }
    void ProducePartC() const override
    {
        this->product->parts_.push_back("PartC1");
    }

    Product1 *GetProduct()
    {
        Product1 *result = this->product;
        this->Reset();
        return result;
    }
};

class Director
{
private:
    Builder *builder;

public:
    void set_builder(Builder *builder)
    {
        this->builder = builder;
    }
    void BuildMinimalViableProduct()
    {
        this->builder->ProducePartA();
    }
    void BuildFullFeatureProduct()
    {
        this->builder->ProducePartA();
        this->builder->ProducePartB();
        this->builder->ProducePartC();
    }
};

void ClientCode(Director &director)
{
    ConcreteBuilder1 *builder = new ConcreteBuilder1();
    director.set_builder(builder);
    std::cout << "Standard basic product:\n";
    director.BuildMinimalViableProduct();

    Product1 *p = builder->GetProduct();
    p->ListParts();

    std::cout << "Standard full featured product:\n";
    director.BuildFullFeatureProduct();

    p = builder->GetProduct();
    p->ListParts();

    std::cout << "Custom product:\n";
    builder->ProducePartA();
    builder->ProducePartB();
    builder->ProducePartC();
    p->ListParts();
    
    delete p;
    delete builder;
}
int main(int argc, char const *argv[])
{
    Director *director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}

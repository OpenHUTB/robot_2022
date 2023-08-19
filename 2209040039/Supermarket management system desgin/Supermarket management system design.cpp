#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    int product_id;
    string product_name;
    double cost_price;
    double selling_price;
    int daily_sales;
    int stock;
    string producer;

    Product(int id, string name, double cost, double selling, int sales, int stock, string producer) {
        product_id = id;
        product_name = name;
        cost_price = cost;
        selling_price = selling;
        daily_sales = sales;
        this->stock = stock;
        this->producer = producer;
    }
};

class Supermarket {
private:
    vector<Product> products;

public:
    void add_product(Product product) {
        products.push_back(product);
    }

    Product* search_by_id(int product_id) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_id == product_id) {
                return &products[i];
            }
        }
        return nullptr;
    }

    Product* search_by_name(string product_name) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_name == product_name) {
                return &products[i];
            }
        }
        return nullptr;
    }

    void sort_by_selling_price() {
        sort(products.begin(), products.end(), [](const Product& p1, const Product& p2) {
            return p1.selling_price > p2.selling_price;
            });
    }

    void sort_by_daily_sales() {
        sort(products.begin(), products.end(), [](const Product& p1, const Product& p2) {
            return p1.daily_sales > p2.daily_sales;
            });
    }

    bool delete_product(int product_id) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_id == product_id) {
                products.erase(products.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool modify_product(int product_id, Product new_product) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].product_id == product_id) {
                products[i] = new_product;
                return true;
            }
        }
        return false;
    }

    double daily_profit_analysis() {
        double total_profit = 0;
        for (const auto& product : products) {
            double profit = (product.selling_price - product.cost_price) * product.daily_sales;
            total_profit += profit;
        }
        return total_profit;
    }

    void print_product_info() {
        for (const auto& product : products) {
            cout << "货物编号: " << product.product_id << endl;
            cout << "货物名称: " << product.product_name << endl;
            cout << "进价: " << product.cost_price << endl;
            cout << "销售价: " << product.selling_price << endl;
            cout << "日销售量: " << product.daily_sales << endl;
            cout << "库存: " << product.stock << endl;
            cout << "生产者: " << product.producer << endl;
            cout << endl;
        }
    }
};

int main() {
    Supermarket supermarket;

    // 添加商品的记录
    Product p1(1, "商品1", 10.0, 20.0, 100, 50, "生产者1");
    Product p2(2, "商品2", 15.0, 25.0, 80, 60, "生产者2");
    supermarket.add_product(p1);
    supermarket.add_product(p2);

    // 查询商品
    Product* product = supermarket.search_by_id(1);
    if (product != nullptr) {
        cout << "查询结果：货物名称 - " << product->product_name << endl;
    }
    else {
        cout << "未找到该商品" << endl;
    }

    // 对商品数据排序
    supermarket.sort_by_selling_price();
    cout << "按销售价降序排序后的商品信息：" << endl;
    supermarket.print_product_info();

    // 删除商品记录
    bool deleted = supermarket.delete_product(2);
    if (deleted) {
        cout << "商品记录删除成功" << endl;
    }
    else {
        cout << "未找到要删除的商品记录" << endl;
    }

    // 修改商品记录
    Product new_product(1, "新商品1", 8.0, 18.0, 120, 40, "新生产者1");
    bool modified = supermarket.modify_product(1, new_product);
    if (modified) {
        cout << "商品记录修改成功" << endl;
    }
    else {
        cout << "未找到要修改的商品记录" << endl;
    }

    // 日销售盈利分析
    double profit = supermarket.daily_profit_analysis();
    cout << "日销售盈利总额：" << profit << endl;

    // 输出商品信息表
    cout << "商品信息表：" << endl;
    supermarket.print_product_info();

    return 0;
}
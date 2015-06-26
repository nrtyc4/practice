#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>

class TodoItem;
class Category {
public:
        Category (std::string name) : name(name) { }

        void addToCategory(TodoItem* item) {
            items.push_back(item);
        }

        void removeFromCategory(const TodoItem* item) {
            auto it = std::find(items.begin(), items.end(), item);
            if (it != items.end()) { items.erase(it); }
        }

        static Category combine(const Category &left, const Category &right) {
            Category combined(left.getName() + ", " + right.getName());

            std::vector<TodoItem*> sortedLeft(left.items);
            std::vector<TodoItem*> sortedRight(right.items);

            std::sort(sortedLeft.begin(), sortedLeft.end());
            std::sort(sortedRight.begin(), sortedRight.end());
            std::set_intersection(sortedLeft.begin(), sortedLeft.end(), sortedRight.begin(), sortedRight.end(), back_inserter(combined.items));

            return combined;
        }

        std::string getName() const {
            return name;
        }

        bool operator == (const Category& a) const {
            return a.getName() == getName();
        }

        bool operator!=(const Category& a) const {
            return a != *this;
        }

        bool operator<(const Category& a) const {
            return this->getName() < a.getName();
        }

        friend std::ostream& operator<<(std::ostream& os, const Category& category);

private:
            std::string name;
            std::vector<TodoItem*> items;
};

class TodoItem {
public:
    TodoItem(const std::string &item) : task(item) { }

    void update(const std::string &item) {
        task = item;
    }

    std::string getTask() const {
        return task;
    }

    bool operator==(const TodoItem& a) const {
        return a.getTask() == getTask();
    }

    bool operator!=(const TodoItem& a) const {
        return a != *this;
    }

    bool operator<(const TodoItem& a) const {
        return this->getTask() < a.getTask();
    }

    friend std::ostream& operator<<(std::ostream& os, const TodoItem& item) {
        os << item.getTask();
        return os; 
    }
private:
    std::string task;
};

inline std::ostream& operator<<(std::ostream& os, const Category& category) {
    os << "----" << std::endl;
    for(auto &item : category.items) {
        os << *item << std::endl;
    }
    return os;
}

class TodoList {
public:
    void add(const std::string &task, const std::string &category = "No Category") {
        auto catPtr = find(categories.begin(), categories.end(), Category(category));
        
        if (catPtr == categories.end()) {
            categories.push_back(Category(category));
            catPtr = find(categories.begin(), categories.end(), Category(category));
        }

        for ( auto &item : items ) {
            if (item == TodoItem(task)) {
                catPtr->addToCategory(&item);
                return;
            }
        }

        items.push_back(TodoItem(task));
        catPtr->addToCategory(&items.back());

        template<typename ... args>
        void add(const std::string &task, const std::string &category, args... otherCategories) {
            add(task, category);
            add(task, otherCategories...);
        }

        void update(const std::string &oldTask, const string &newTask) {
            auto itemIt = find(items.begin(), items.end(), TodoItem(oldTask));
            if (itemIt != items.end()) { itemIt->update(newTask); }   
        }

        template<typename ... args>
        void viewList(std::ostream& os, args ... categoriesArgs) const {
            os << getCategory(categoriesArgs...);
        }
    }
private:
    Category getCategory(const std::string category) const {
        return *std::find(categories.begin(), categories.end(), Category(category));
    }

    template<typename ... args>
    Category getCategory(const std::string category, args ... categoriesArgs) const {
        return Category::combine(*find(categories.begin(), categories.end(), Category(category)), getCategory(categoriesArgs...));
    }

    std::deque<TodoItem> items;
    std::vector<Category> categories;
};

int main() {
    TodoList list;

    list.add("A pixel is not a pixel is not a pixel", "Programming");
    list.add("The scheme programming language", "Programming");
    list.add("Memory in C", "Programming");
    list.add("Haskell's school of music", "Music", "Programming");
    list.add("Algorithmic symphonies from one line of code", "Music", "Programming");

    list.add("Modes in folk music", "Music");
    list.add("The use of the melodic minor scale", "Music");

    list.viewList(std::cout, "Music");
    std::cout << std::endl;
    list.viewList(std::cout, "Programming");
    std::cout << std::endl;

    list.update("Algorithmic symphonies from one line of code", "Algorithmic symphonies from one line of code in C");
    list.viewList(std::cout, "Programming", "Music");
    std::cout << std::endl;

    return 0;
}

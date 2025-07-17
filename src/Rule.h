#pragma once 
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "Predicate.h"
#include "XCSP3CoreParser.h"
#include "utils.h"

class CHRCallbacks; 

class Rule {
protected:
    std::string name;
    std::vector<Predicate> head;

    static std::string prefix_op ;
    static bool minimalMode;
    std::string symbol = "==>";
    std::vector<std::string> guard;
    std::vector<Predicate> tail;
    CHRCallbacks* callback = nullptr;  

public:
    Rule(const std::string& ruleName = "", CHRCallbacks* cb = nullptr)
        : name(ruleName), callback(cb) {
        toCHR();
    }

    virtual ~Rule() = default;
    
    static void setprefix_op(const std::string & s);
    static void enable_minimalMode();
    void setCHRCallbacks(CHRCallbacks* cb) { callback = cb; }
    CHRCallbacks* getCHRCallbacks() const { return callback; }
    virtual std::string toCHR()  {
            std::ostringstream oss;

            if (!name.empty())
                oss << name << " @ ";

            for (size_t i = 0; i < head.size(); ++i) {
                oss << head[i].toString();
                if (i + 1 < head.size()) oss << ", ";
            }

            oss << " " << symbol << " ";

            if (!guard.empty()) {
                for (size_t i = 0; i < guard.size(); ++i) {
                    oss << guard[i];
                    if (i + 1 < guard.size()) oss << ", ";
                }
                oss << " | ";
            }

            for (size_t i = 0; i < tail.size(); ++i) {
                oss << tail[i].toString();
                if (i + 1 < tail.size()) oss << ", ";
            }

            oss << ";;";
            return oss.str();
        }

        virtual std::string toString() {
            return Rule::toCHR();
        }
        virtual void finalize() = 0 ;

        void setName(const std::string& n) { name = n; }
        void setSymbol(const std::string& s) { symbol = s; }
        void addHead(const Predicate& h) {
            if (std::find(head.begin(), head.end(), h) == head.end()) {
                head.push_back(h);
            }
        }

        void addTail(const Predicate& t) {
            if (std::find(tail.begin(), tail.end(), t) == tail.end()) {
                tail.push_back(t);
            }
        }
        void addGuard(const std::string& g) { guard.push_back(g); }

        void setHead(const std::vector<Predicate>& h) { head = h; }
        void setTail(const std::vector<Predicate>& t) { tail = t; }
        void setGuard(const std::vector<std::string>& g) { guard = g; }

        const std::vector<Predicate>& getHead() const { return head; }
        const std::vector<Predicate>& getTail() const { return tail; }
        const std::vector<std::string>& getGuard() const { return guard; }
        const std::string& getSymbol() const { return symbol; }
        const std::string& getName() const { return name; }
    };

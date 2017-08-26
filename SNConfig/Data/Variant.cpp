#include "Variant.h"
#include <stdexcept>

namespace SurgeNight
{

Variant::Variant() : m_type(VAR_TYPE_INT)
{
    m_data.i = 0;
}

Variant::~Variant()
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
}

Variant::Variant(const Variant &var) : m_type(var.m_type)
{
    if(VAR_TYPE_STR == m_type)
        new (&m_data.str) std::string();
    switch (m_type) {
        case VAR_TYPE_INT:
            m_data.i = var.m_data.i;
            break;
        case VAR_TYPE_FLOAT:
            m_data.f = var.m_data.f;
            break;
        case VAR_TYPE_DOUBLE:
            m_data.d = var.m_data.d;
            break;
        case VAR_TYPE_CHAR:
            m_data.ch = var.m_data.ch;
            break;
        case VAR_TYPE_STR:
            m_data.str = var.m_data.str;
            break;
        case VAR_TYPE_OBJ:
            m_data.str = var.m_data.obj->copy();
            break;
        case VAR_TYPE_LIST:
            m_data.str = var.m_data.str;
            break;
    }
}

Variant& Variant::operator=(const Variant &var)
{
    if(VAR_TYPE_STR == m_type && m_type != var.m_type)
        m_data.str.~basic_string<char>();
    if(VAR_TYPE_LIST == m_type && m_type != var.m_type)
        m_data.list->~ListVariant();
    if(VAR_TYPE_OBJ == m_type && m_type != var.m_type)
        m_data.obj->~ObjectVariant();
    if (VAR_TYPE_STR != m_type && VAR_TYPE_STR == var.m_type)
        new (&m_data.str) std::string();
    if (VAR_TYPE_LIST != m_type && VAR_TYPE_LIST == var.m_type)
        new (&m_data.list) ListVariant();
    if (VAR_TYPE_OBJ != m_type && VAR_TYPE_OBJ == var.m_type)
        new (&m_data.obj) ObjectVariant();
    m_type = var.m_type;
    switch (m_type) {
        case VAR_TYPE_BOOL:
            m_data.b = var.m_data.b;
            break;
        case VAR_TYPE_INT:
            m_data.i = var.m_data.i;
            break;
        case VAR_TYPE_UINT:
            m_data.ui = var.m_data.ui;
            break;
        case VAR_TYPE_FLOAT:
            m_data.f = var.m_data.f;
            break;
        case VAR_TYPE_DOUBLE:
            m_data.d = var.m_data.d;
            break;
        case VAR_TYPE_CHAR:
            m_data.ch = var.m_data.ch;
            break;
        case VAR_TYPE_UCHAR:
            m_data.uch = var.m_data.uch;
            break;
        case VAR_TYPE_STR:
            m_data.str = var.m_data.str;
            break;
        case VAR_TYPE_LIST:
            m_data.list = var.m_data.list; // TODO  need fix
            break;
        case VAR_TYPE_OBJ:
            m_data.obj = var.m_data.obj; // TODO need fix
            break;
    }
    return *this;
}

Variant::Variant(const bool b) : m_type(VAR_TYPE_BOOL)
{
    m_data.b = b;
}

Variant::Variant(const int i) : m_type(VAR_TYPE_INT)
{
    m_data.i = i;
}

Variant::Variant(const unsigned int i) : m_type(VAR_TYPE_UINT)
{
    m_data.ui = ui;
}

Variant::Variant(const float f) : m_type(VAR_TYPE_FLOAT)
{
    m_data.f = f;
}

Variant::Variant(const double d) : m_type(VAR_TYPE_DOUBLE)
{
    m_data.d = d;
}

Variant::Variant(const char ch) : m_type(VAR_TYPE_CHAR)
{
    m_data.ch = ch;
}

Variant::Variant(const unsigned char uch) : m_type(VAR_TYPE_UCHAR)
{
    m_data.uch = uch;
}

Variant::Variant(const std::string &str) : m_type(VAR_TYPE_STR)
{
    new (&m_data.str) std::string();
    m_data.str = str;
}

Variant::Variant(const std::string &&str) : m_type(VAR_TYPE_STR)
{
    new (&m_data.str) std::string();
    m_data.str = std::move(str);
}

Variant& Variant::operator=(const bool b)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_BOOL;
    m_data.b = b;
    return *this;
}

Variant& Variant::operator=(const int i)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_INT;
    m_data.i = i;
    return *this;
}

Variant& Variant::operator=(const unsigned int ui)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_UINT;
    m_data.ui = ui;
    return *this;
}

Variant& Variant::operator=(const float f)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_FLOAT;
    m_data.f = f;
    return *this;
}

Variant& Variant::operator=(const double d)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_DOUBLE;
    m_data.d = d;
    return *this;
}

Variant& Variant::operator=(const char ch)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_CHAR;
    m_data.ch = ch;
    return *this;
}

Variant& Variant::operator=(const unsigned char uch)
{
    if (VAR_TYPE_STR == m_type)
        m_data.str.~basic_string<char>();
    else if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    m_type = VAR_TYPE_UCHAR;
    m_data.uch = uch;
    return *this;
}

Variant& Variant::operator=(const std::string &str)
{
    if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    if (VAR_TYPE_STR != m_type)
        new (&m_data.str) std::string();
    m_type = VAR_TYPE_STR;
    m_data.str = str;
    return *this;
}

Variant& Variant::operator=(const std::string &&str)
{
    if (VAR_TYPE_LIST == m_type)
        m_data.list->~ListVariant();
    else if (VAR_TYPE_OBJ == m_type)
        m_data.obj->~ObjectVariant();
    if (VAR_TYPE_STR != m_type)
        new (&m_data.str) std::string();
    m_type = VAR_TYPE_STR;
    m_data.str = std::move(str);
    return *this;
}

const bool Variant::asBool() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return m_data.b;
    }
    else if (VAR_TYPE_INT == m_type) {
        return static_cast<bool>(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return static_cast<bool>(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return static_cast<bool>(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return static_cast<bool>(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return static_cast<bool>(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return static_cast<bool>(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        if (m_data.str.size() < 4)
            return false;
        return (m_data.str[0] == 'T' || m_data.str[0] == 't') ||
               (m_data.str[0] == 'R' || m_data.str[0] == 'r') ||
               (m_data.str[0] == 'U' || m_data.str[0] == 'u') ||
               (m_data.str[0] == 'E' || m_data.str[0] == 'e');
    }
    else if (VAR_TYPE_LIST == m_type) {
        return false;
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return false;
    }
    return false;
}

const int Variant::asInt() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return static_cast<int>(m_data.b);
    }
    else if (VAR_TYPE_INT == m_type) {
        return m_data.i;
    }
    else if (VAR_TYPE_UINT == m_type) {
        return static_cast<int>(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return static_cast<int>(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return static_cast<int>(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return static_cast<int>(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return static_cast<int>(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        try {
            int i = std::stoi(m_data.str);
            return i;
        }
        catch (const std::invalid_argument&) {
            return 0;
        }
        catch (const std::out_of_range&) {
            return 0;
        }
    }
    else if (VAR_TYPE_LIST == m_type) {
        return 0;
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return 0;
    }
    return 0;
}

const unsigned int Variant::asUInt() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return static_cast<unsigned int>(m_data.b);
    }
    else if (VAR_TYPE_INT == m_type) {
        return static_cast<unsigned int>(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return m_data.ui;
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return static_cast<unsigned int>(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return static_cast<unsigned int>(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return static_cast<unsigned int>(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return static_cast<unsigned int>(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        try {
            unsigned int ui = std::stoul(m_data.str);
            return ui;
        }
        catch (const std::invalid_argument&) {
            return 0u;
        }
        catch (const std::out_of_range&) {
            return 0u;
        }
    }
    else if (VAR_TYPE_LIST == m_type) {
        return 0u;
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return 0u;
    }
    return 0u;
}

const float Variant::asFloat() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return static_cast<float>(m_data.b);
    }
    else if (VAR_TYPE_INT == m_type) {
        return static_cast<float>(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return static_cast<float>(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return m_data.f;
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return static_cast<float>(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return static_cast<float>(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return static_cast<float>(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        try {
            float f = std::stof(m_data.str);
            return f;
        }
        catch (const std::invalid_argument&) {
            return 0.0f;
        }
        catch (const std::out_of_range&) {
            return 0.0f;
        }
    }
    else if (VAR_TYPE_LIST == m_type) {
        return 0.0f;
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return 0.0f;
    }
    return 0.0f;
}

const double Variant::asDouble() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return static_cast<double>(m_data.b);
    }
    else if (VAR_TYPE_INT == m_type) {
        return static_cast<double>(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return static_cast<double>(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return static_cast<double>(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return m_data.d;
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return static_cast<double>(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return static_cast<double>(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        try {
            double d = std::stod(m_data.str);
            return d;
        }
        catch (const std::invalid_argument&) {
            return 0.0;
        }
        catch (const std::out_of_range&) {
            return 0.0;
        }
    }
    else if (VAR_TYPE_LIST == m_type) {
        return 0.0;
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return 0.0;
    }
    return 0.0;
}

const char Variant::asChar() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return static_cast<char>(m_data.b);
    }
    else if (VAR_TYPE_INT == m_type) {
        return static_cast<char>(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return static_cast<char>(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return static_cast<char>(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return static_cast<char>(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return m_data.ch;
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return static_cast<char>(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        return m_data.str.size() < 1 ? '\0' : m_data.str[0];
    }
    else if (VAR_TYPE_LIST == m_type) {
        return '\0';
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return '\0';
    }
    return '\0';
}

const unsigned char Variant::asUChar() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return static_cast<unsigned char>(m_data.b);
    }
    else if (VAR_TYPE_INT == m_type) {
        return static_cast<unsigned char>(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return static_cast<unsigned char>(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return static_cast<unsigned char>(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return static_cast<unsigned char>(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return static_cast<unsigned char>(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return m_data.uch;
    }
    else if (VAR_TYPE_STR == m_type) {
        return m_data.str.size() < 1 ? '\0' : m_data.str[0];
    }
    else if (VAR_TYPE_LIST == m_type) {
        return '\0';
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return '\0';
    }
    return '\0';
}

const std::string Variant::asString() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return m_data.b ? "true" : "false";
    }
    else if (VAR_TYPE_INT == m_type) {
        return std::to_string(m_data.i);
    }
    else if (VAR_TYPE_UINT == m_type) {
        return std::to_string(m_data.ui);
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return std::to_string(m_data.f);
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return std::to_string(m_data.d);
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return std::to_string(m_data.ch);
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return std::to_string(m_data.uch);
    }
    else if (VAR_TYPE_STR == m_type) {
        return m_data.str;
    }
    else if (VAR_TYPE_LIST == m_type) {
        return "";
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return "";
    }
    return "";
}

const ListVariant Variant::asList() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return ListVariant{ m_data.b };
    }
    else if (VAR_TYPE_INT == m_type) {
        return ListVariant{ m_data.i };
    }
    else if (VAR_TYPE_UINT == m_type) {
        return ListVariant{ m_data.ui };
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return ListVariant{ m_data.f };
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return ListVariant{ m_data.d };
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return ListVariant{ m_data.ch };
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return ListVariant{ m_data.uch };
    }
    else if (VAR_TYPE_STR == m_type) {
        return ListVariant{ m_data.str };
    }
    else if (VAR_TYPE_LIST == m_type) {
        return *m_data.list;
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return ListVariant{ *m_data.obj };
    }
    return ListVariant();
}

const ObjectVariant Variant::asObject() const
{
    if (VAR_TYPE_BOOL == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_INT == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_UINT == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_FLOAT == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_DOUBLE == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_CHAR == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_UCHAR == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_STR == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_LIST == m_type) {
        return ObjectVariant();
    }
    else if (VAR_TYPE_OBJ == m_type) {
        return *m_data.obj;
    }
    return ObjectVariant();
}

const bool Variant::isBool() const
{
    return VAR_TYPE_BOOL == m_type;
}

const bool Variant::isInt() const
{
    return VAR_TYPE_INT == m_type;
}

const bool Variant::isUInt() const
{
    return VAR_TYPE_UINT == m_type;
}

const bool Variant::isFloat() const
{
    return VAR_TYPE_FLOAT == m_type;
}

const bool Variant::isDouble() const
{
    return VAR_TYPE_DOUBLE == m_type;
}

const bool Variant::isChar() const
{
    return VAR_TYPE_CHAR == m_type;
}

const bool Variant::isUChar() const
{
    return VAR_TYPE_UCHAR == m_type;
}

const bool Variant::isString() const
{
    return VAR_TYPE_STR == m_type;
}

const bool Variant::isList() const
{
    return VAR_TYPE_LIST == m_type;
}

const bool Variant::isObject() const
{
    return VAR_TYPE_OBJ == m_type;
}

}
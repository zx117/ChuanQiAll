class Proxy
{
    GenericPropertyObjectPtr<InterfaceType>& propObj;
    std::string key;

public:
    Proxy(GenericPropertyObjectPtr<InterfaceType>& propObj, std::string key)
        : propObj(propObj)
        , key(std::move(key)){};

    template <typename U, std::enable_if_t<is_ct_conv<U>::value, int> = 0>
    operator U()  // rvalue use
    {
        return static_cast<U>(propObj.getPropertyValue(key));
    }

    Proxy& operator=(const BaseObjectPtr& obj)  // lvalue use
    {
        propObj.setPropertyValue(key, obj);
        return *this;
    }
};

Proxy operator[](const std::string& propName) const
{
    return Proxy(*this, propName);
}

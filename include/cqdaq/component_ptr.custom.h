
/*!
 * @brief Notifies the component that it is being removed.
 *
 * Call `remove` on the component to mark it as removed. It's up to the implementation
 * to define what is does on the act of removal. Basic implementation of `Component`
 * will switch it to inactive state and it cannot be activated again.
 */
void remove() const
{
    if (this->object == nullptr)
        throw daq::InvalidParameterException();

    IRemovable* removable;
    auto errCode = this->object->borrowInterface(IRemovable::Id, reinterpret_cast<void**>(&removable));
    if (CQDAQ_FAILED(errCode))
    {
        if (errCode == CQDAQ_ERR_NOINTERFACE)
            return;
        daq::checkErrorInfo(errCode);
    }

    errCode = removable->remove();
    daq::checkErrorInfo(errCode);
}

/*!
 * @brief Returns True if component was removed.
 * @return True if component was removed; otherwise False.
 */
bool isRemoved() const
{
    if (this->object == nullptr)
        throw daq::InvalidParameterException();

    IRemovable* removable;
    auto errCode = this->object->borrowInterface(IRemovable::Id, reinterpret_cast<void**>(&removable));
    daq::checkErrorInfo(errCode);

    Bool removed;
    errCode = removable->isRemoved(&removed);
    daq::checkErrorInfo(errCode);

    return removed;
}

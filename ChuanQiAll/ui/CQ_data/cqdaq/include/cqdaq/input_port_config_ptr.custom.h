
/*!
 * @brief Notifies the input port that it is being removed.
 *
 * Call `remove` on the input port to mark it as removed. It will also disconnect all 
 * the signals connected to it.
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
 * @brief Returns True if the input port was removed.
 * @return True if the input port was removed; otherwise False.
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

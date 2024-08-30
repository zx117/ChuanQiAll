/*!
 * @brief Sets the continuation to only execute after this task completes.
 * Be careful of forming cycles as tasks whose dependencies cannot be satisfied will never execute.
 * @param continuation The task that should wait for this one to complete.
 * @throws DaqNotSupportedException If the @p continuation implementation was not crated by the scheduler library.
 * @returns the continuation task
 */
TaskPtr then(const daq::TaskPtr& continuation) const
{
    if (this->object == nullptr)
        throw daq::InvalidParameterException();

    auto errCode = this->object->then(continuation);
    daq::checkErrorInfo(errCode);

    return continuation;
}

/*!
 * @brief Sets the continuation to only execute after this task completes.
 * Be careful of forming cycles as tasks whose dependencies cannot be satisfied will never execute.
 * @param continuation The task that should wait for this one to complete.
 * @throws DaqNotSupportedException If the @p continuation implementation was not crated by the scheduler library.
 * @returns the continuation task
 */
TaskPtr then(daq::ITask* continuation) const
{
    return then(daq::TaskPtr(continuation));
}

/*!
 * @brief Sets the continuation to only execute after this task completes.
 * Be careful of forming cycles as tasks whose dependencies cannot be satisfied will never execute.
 * @param continuation The task that should wait for this one to complete.
 * @param name The name used for diagnostics.
 * @throws DaqNotSupportedException If the @p work implementation was not crated by the scheduler library.
 * @returns the continuation task created from the @p work procedure.
 */
TaskPtr then(daq::ProcedurePtr work, daq::StringPtr name = "") const
{
    if (this->object == nullptr)
        throw daq::InvalidParameterException();

    TaskPtr continuation = Task_Create(work, name);
    auto errCode = this->object->then(continuation);
    daq::checkErrorInfo(errCode);

    return continuation;
}

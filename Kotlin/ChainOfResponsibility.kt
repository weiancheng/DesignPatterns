class LoggerLevel() {
    companion object {
        val DEBUG = 1
        val INFO = 2
        val WARNING = 3
        val ERROR = 4
    }
}
abstract class LoggerHandler() {
    private var handler: LoggerHandler? = null
    public fun setHandler(handler: LoggerHandler?) {
        this.handler = handler
    }
    protected fun next(): LoggerHandler? = handler
    abstract fun message(level: Int, msg: String)
}
class Logger(): LoggerHandler() {
    override fun message(level: Int, msg: String) {
        super.next().let {
            if (it != null)
                it.message(level, msg)
        }
    }
}
class Debug(): LoggerHandler() {
    override fun message(level: Int, msg: String) {
        if (level.equals(LoggerLevel.DEBUG)) {
            println("[Debug] " + msg)
        } else {
            super.next().let {
                if (it != null) {
                    it.message(level, msg)
                }
            }
        }
    }
}
class Warning(): LoggerHandler() {
    override fun message(level: Int, msg: String) {
        if (level.equals(LoggerLevel.WARNING)) {
            println("[Warning] " + msg)
        } else {
            super.next().let {
                if (it != null)
                    it.message(level, msg)
            }
        }
    }
}
class Info(): LoggerHandler() {
    override fun message(level: Int, msg: String) {
        if (level.equals(LoggerLevel.INFO)) {
            println("[Info] " + msg)
        } else {
            super.next().let {
                if (it != null)
                    it.message(level, msg)
            }
        }
    }
}
class Error(): LoggerHandler() {
    override fun message(level: Int, msg: String) {
        if (level.equals(LoggerLevel.ERROR)) {
            println("[Error] " + msg)
        } else {
            super.next().let {
                if (it != null)
                    it.message(level, msg)
            }
        }
    }
}
fun main() {
    println("This is Chain of Response")
    val logger = Logger()
    val debug = Debug()
    val warning = Warning()
    val info = Info()
    val error = Error()
    logger.setHandler(debug)
    debug.setHandler(info)
    info.setHandler(warning)
    warning.setHandler(error)
    error.setHandler(null)
    logger.message(LoggerLevel.ERROR, "segmentation fault")
}
